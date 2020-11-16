// Comando para compilar e executar
/* 
 gcc ./Codigos/lista_5/main.c ./Codigos/lista_5/pilhaEncadeada.h ./Codigos/lista_5/pilhaEncadeada.c ./Codigos/lista_5/hanoi.h ./Codigos/lista_5/hanoi.c -o exe -lm && ./exe
*/

// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "hanoi.h"

// funcao principal
int main(void) {

  // no início a pilha está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da pilha
  Pilha *tubo1 = criarTubo(0);
  Pilha *tubo2 = criarTubo(1);
  Pilha *tubo3 = criarTubo(1);
  int de, para, opcao;

  // menu de opções para execuções de operações sobre a pilha
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Movimentar cubo");
    printf("\n2 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:

        // Movimentar cubo
        printf("\nDe qual tubo deseja retirar o cubo? ");
        printf("\n1 - 2 - 3 \n");
        scanf("%d", &de);

        printf("\nPara qual tubo deseja enviar o cubo? ");
        printf("\n1 - 2 - 3 \n");
        scanf("%d", &para);

        Pilha **origem = de == 1 ? &tubo1 : (de == 2 ? &tubo2 : &tubo3);

        Pilha **destino = de == 1 ? &tubo1 : (de == 2 ? &tubo2 : &tubo3);
       
        if(movimentarCubo(*origem, *destino)){
          printf("\nCubo movimentado.");
          if(!printTubos(tubo1, tubo2, tubo3)){
            printf("\nNão foi possível mostrar os tubos.");
          }
        }else{
          printf("\nNão foi possível movimentar o cubo.");
        }
        
        break;

      case 2:

        // libera memória e finaliza programa
        liberarTubo(tubo1, tubo2, tubo3);

        printf("\nFinalizando...\n");
        break;

      default:
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 2);

  return 0;
}