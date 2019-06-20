#include <stdio.h>
#include <stdlib.h>

/* Definicoes, para facilitar o uso da funcao para desenhar o mapa */
#define CHAO 0
#define PAREDE 1
#define VOCE 2
#define TETO 5
#define CHEGADA 6

#define OK 1
#define ERRO 2

/* Usuarios de Windows, troquem "clear" por "cls" */
#define LIMPARTELA "cls"
int    coluna_atual = 0,
   linha_atual = 1;

/* O Mapa */
int mapa[30][60] = { 
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,5,5,5,0,1,0,1,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,1,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,
		1,0,0,0,5,5,5,5,5,5,5,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,5,5,5,5,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,
		1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,5,5,5,5,5,5,5,5,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,
		1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,5,5,5,0,1,
		1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,5,5,5,5,5,5,5,0,1,
		1,0,0,0,1,5,5,5,5,1,5,5,5,5,5,5,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,
		1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,5,5,5,5,5,1,0,0,0,0,0,0,0,1,5,5,5,5,5,5,5,5,5,5,5,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,5,5,5,5,5,5,1,0,0,0,1,5,5,5,5,5,5,5,5,5,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,
		1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,1,5,5,5,5,5,5,5,5,5,5,0,1,0,0,0,1,0,0,5,5,5,5,5,5,5,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,5,5,5,5,5,5,5,5,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,5,5,5,5,5,5,5,5,5,5,1,0,0,0,1,5,5,5,5,5,5,5,5,5,5,5,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,5,5,5,5,5,5,5,5,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,
		1,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,5,5,5,5,5,5,5,5,5,5,0,0,1,0,0,0,1,0,0,0,1,0,0,5,5,5,5,5,5,5,5,5,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
};

/* Funcao para desenhar o Mapa */
int desenhar_mapa()
{
   int linha,coluna;
   for (linha=0;linha<30;linha++) {
      for (coluna=0;coluna<60;coluna++) {
         if ((linha == linha_atual) && (coluna == coluna_atual)) {
            printf("$");
            continue;
         }
         if (mapa[linha][coluna] == CHAO)
           				 printf(" ");
         if (mapa[linha][coluna] == PAREDE)
          				  printf("|");
         if (mapa [linha][coluna] == TETO)
		 				printf ("-");
      }
      printf("\n");
   }
   return OK;
}

int main()
{
   char movimento;
   while ((movimento != 'x') && (movimento != 'X')) {
      system(LIMPARTELA);
      desenhar_mapa();
      printf("\n\n  (W)\n(A)+(D)\n  (S)\n\n"); /* Imprime as direcoes */
      if ((scanf("%c",&movimento))==0) {
         printf("mensagem de erro..\n");
         getchar(); getchar();
         return ERRO;
      }
      if ((movimento == 'w') || (movimento == 'W')) {
         linha_atual = linha_atual - 1;
         /* Se n�o for chao ou grama ele volta pra posicao anterior */
         if (mapa[linha_atual][coluna_atual] != CHAO){
            linha_atual = linha_atual + 1;
            printf("\n\nups.. ali nou -(TLT)-\n");
            getchar(); getchar();
         }
      }
      if ((movimento == 's') || (movimento == 'S')) {
         linha_atual = linha_atual + 1;
         /* Se n�o for chao ou grama ele volta pra posicao anterior */
         if (mapa[linha_atual][coluna_atual] != CHAO){
            linha_atual = linha_atual - 1;
            printf("\n\nups.. joga direito \n");
            getchar(); getchar();
         }
      }
      if ((movimento == 'd') || (movimento == 'D')) {
         coluna_atual = coluna_atual + 1;
         /* Se n�o for chao ou grama ele volta pra posicao anterior */
         if ((mapa[linha_atual][coluna_atual] != CHAO) && (mapa[linha_atual][coluna_atual] != CHEGADA)){
            coluna_atual = coluna_atual - 1;
            printf("\n\nups.. ali nau -(TLT)-\n");
            getchar(); getchar();
         }
      }
      if ((movimento == 'a') || (movimento == 'A')) {
         coluna_atual = coluna_atual - 1;
         /* Se n�o for chao ou grama ele volta pra posicao anterior */
         if (mapa[linha_atual][coluna_atual] != CHAO){
            coluna_atual = coluna_atual + 1;
            printf("\n\nups.. voce nao faz \n nada certo -(TLT)-\n");
            getchar(); getchar();
         }
      }
      if(mapa[linha_atual][coluna_atual] == CHEGADA){
	  	coluna_atual = coluna_atual;
         
        	 printf("\n\nups.. VOCE GANHOU OTARIO  \n");
         	/* Se n�o for chao ou grama ele volta pra posicao anterior */
         	if (mapa[linha_atual][coluna_atual] == CHEGADA){
            	coluna_atual = coluna_atual;
            	printf("\n nups.. VOCE GANHOU OTARIO  \n");
            	getchar(); getchar();
         }
	  	}
	  }
      
	}
//	   while ((movimento != 'x') && (movimento != 'X') && (mapa[linha_atual][coluna_atual] == CHEGADA)) {
//         coluna_atual = coluna_atual;
//         
//         printf("\n\nups.. VOCE GANHOU OTARIO  \n");
//         /* Se n�o for chao ou grama ele volta pra posicao anterior */
//         if (mapa[linha_atual][coluna_atual] == CHEGADA){
//            coluna_atual = coluna_atual;
//            printf("\n nups.. VOCE GANHOU OTARIO  \n");
//            getchar(); getchar();
//         }
//      }
//}

