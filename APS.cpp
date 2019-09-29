#include <stdio.h>
#include <conio.h>  // getche
#include <stdlib.h> // exit
#include <string.h> // stricmp
#include <ctype.h>  // toupper
#include <locale.h> // setlocale(LC_ALL, "Portuguese");

/***********************************************/
/* Definição dos Registros                     */
/***********************************************/

typedef struct { // registro para instituições
	char nome[22], logo[22], tamanho[22];
}NODO;

struct LISTA{
	NODO info;
	struct LISTA * prox;
};

/************************************************
 * Função:   entrada_dados                      *
 * objetivo: rotina para ler dados              *
 * entrada : registro aux (auxiliar)            *
 * saída   : aux atualizada com dados           *
 ************************************************/

void entrada_dados( LISTA* aux ){   // cadastro das instituições

	system("cls");
	printf("\n\n\t------------------- Cadastro --------------------         \n" );
	
    printf( "\n Informe o Nome do aluno: " );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    gets( aux->info.nome );
    
    printf("\n Informe a cor do logo : ");
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    gets( aux->info.logo );
 
    printf("\n Informe o Tamanho: ");
    fflush( stdin );  // limpa buffer do teclado, funciona junto com entrada de dados    
    gets( aux->info.tamanho );
 
    printf( "\n\t-------------------------------------------------" );  
    aux->prox = NULL;    
   
}

/************************************************
 * Função:   inclui                             *
 * objetivo: cadastrar instituições             *
 * entrada : lista                              *
 * saída   : lista com novos elementos          *
 ************************************************/

void  inclui(  LISTA * *lista ){ // função de inclusão
	LISTA *p;
	int contador1, contador2=0;
	
		printf("\n\n\t------------------- Cadastro --------------------         \n" );
		printf("\n Informe o número de registros a ser inserido: ");
		fflush(stdin);
		scanf("%i", &contador1);

		while(contador1 > contador2 ){
		LISTA *no = (LISTA*) malloc ( sizeof (LISTA) ); //aloca espaço em memoria e salva na variavel no
		if( no != NULL ){                            // verifica se conseguiu alocar memoria para o novo registro
		            entrada_dados( no );              // entrada de dados
		            if( *lista == NULL ) {                   // verifica se a lista esta vazia
		                *lista = no; // insere o primeiro registro no endereço fornecido por no
					printf( "\n Registro Incluido!" ); 
					}                        
		            
					else { // se a lista ja tiver um registro no inicio
		                 p = *lista;                 // ponteiro recebe inicio      
		                 while( p->prox != NULL )  // percorre a lista até encontrar o ultimo registro
		                       p = p->prox;
		                 p->prox = no;                  // insere no final da lista
		                 printf( "\n Registro Incluido!" );                  
		                 } // fim if ( *l == NULL )
		       } // fim if( no != NULL )
		   else
		       printf( "\n Lista cheia! " );
		contador2 ++;
		}
	}

/*****************************************************
 * função: ordena_selection                          *
 * objetivo: ordenar a lista pelo cod                *
 * entrada : lista                                   *
 * saída   : lista ordenada                          *
 *****************************************************/
void  ordena_selection( LISTA **lista ){
   LISTA *i;
   LISTA *menor;
   LISTA *j;
   NODO aux ;  // auxiliar para a troca de dados
   
   
    i = *lista;        // posiciona ponteiro auxiliar para anterior no início da lista

    if( *lista == NULL ) // verifica se a lista esta vazia
        printf( "\n Lista Vazia! " );
        else
		if (i->prox==NULL)// verifica se a lista tem apenas um elemento
        printf("\n Lista com 1 Elemento! ");  
        else {
		j = i->prox;
        
		while( i->prox != NULL ){ 
        menor=i; // menor recebe primeiro elemento (elemento apontado por i)

        while ( j != NULL ){   // procura menor codigo enquanto não chegar ao final da lista
        	if( strcmp(j->info.logo,  menor->info.logo) < 0){ //devolve valor < 0 se achar
        menor = j;   // *menor recebe o menor cod
                }
                j=j->prox;  //aponta para o proximo registro
          }  
          if( strcmp(i->info.logo,  menor->info.logo) > 0){ // faz a troca se no reg de i o nome for maior  
				aux = menor->info; // auxiliar recebe o reg com o menor cod
                menor->info=i->info ;
                i->info = aux;  //i recebe o menor valor
      }
          i=i->prox;//atualiza ponteiro i
          j=i->prox;//atualiza ponteiro j para o proximo do i
    }
  //----------------------------------------------------------------------------------------------------------------------
    //APONTAR PRO INICIO DE NOVO
    j = i->prox;
          while( i->prox != NULL ){
         
          menor=i; // menor recebe primeiro elemento (elemento apontado por i)
          
            while ( j != NULL ){  
    			if( strcmp(j->info.logo,  i->info.logo) == 0){
            	if( strcmp(j->info.tamanho,  menor->info.tamanho) < 0){ //devolve valor < 0 se achar
                menor = j;             
           }
        }
                j=j->prox;  //aponta para o proximo registro
    }  
          if( strcmp(j->info.logo,  i->info.logo) == 0){
          if( strcmp(i->info.tamanho,  menor->info.tamanho) > 0){ // faz a troca se no reg de i o nome for maior  
				aux = menor->info; // auxiliar recebe o reg com o menor cod
                menor->info=i->info ; // *menor recebe o reg que i estava apontando
                i->info = aux;  //i recebe o menor valor
      }
      }
          i=i->prox;//atualiza ponteiro i
          j=i->prox;//atualiza ponteiro j para o proximo do i
		}		
	}
           printf( "\n Lista Ordenada!" );            
}	
   
/************************************************
 * imprime_lista                                *
 * objetivo: função para imprimir os dados      *
 * entrada : lista                              *
 * saida: todos cadastros imprimidos            *
 ************************************************/

void imprime_lista( LISTA* aux ) // função imprime todos registros
{
system("cls");
    if( aux == NULL )
        printf( "\n Lista Vazia!" );
		else {
        printf("\n\n\t --------------------Relatório Geral-------------------- ");
        printf("\n\n");
        while( aux != NULL ){    // ponteiro auxiliar para a lista
             
           printf( "\n Cor:               %s", aux->info.logo );	
           printf( "\n Tamanho:  %s", aux->info.tamanho );
           printf( "\n Nome             %s", aux->info.nome );
           printf( "\n\t---------------------------------------------------------" );
        aux = aux->prox;  // aponta para o proximo registro da lista        
		} // fim while( aux != NULL )
 		printf("\n\n");
	} // fim if( aux == NULL )
}


/***********************************************/
/* Programa Principal                          */
/***********************************************/
int main( void ){

	system("cls");

    int op;          // opção do menu
    LISTA *lista=NULL;   // variável do tipo lista
   
    setlocale(LC_ALL, "Portuguese");
    while( 1 ){
         printf( "\n\t----------------------MENU-----------------------" );
         printf( "\n  [1] - Incluir Registro                           " );
         printf( "\n  [2] - Ordenar lista                              " );
		 printf( "\n  [3] - Imprimir Lista                             " );
	     printf( "\n\t-------------------------------------------------  " );
         printf( "\n\t\t\tInforme a Opção: " );
         fflush(stdin);
         scanf("%d", &op);// tecla de opção do menu
         
       
        switch( op ) {
                                       
            case 1:  // rotina inclui registro no final da lista
                    inclui( &lista );    
                    break;          
         
            case 2:  // rotina exclui registro da lista
                   ordena_selection( &lista );
                    break;
                 
            case 3:  // rotina ordena lista
                      imprime_lista( lista );
                    break;
   
            case  0: // término do programa                                                
                    exit( 1 );
                    break;
               
            default :
                    printf( "\n Digite uma Opção!" );
                    break;
                   
         } // switch( op )
 
  fflush( stdin );
 
     }
     
 return 0;
} // fim do programa principal
