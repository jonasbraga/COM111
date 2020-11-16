#include <stdio.h>
#include <stdlib.h>
#include "pilhaEncadeada.h"

int printTubos(Pilha *tubo1, Pilha *tubo2, Pilha *tubo3)
{

Pilha *tubo1a = tubo1;
Pilha *tubo2a = tubo2;
Pilha *tubo3a = tubo3;


  printf("\n------------------");
  printf("\n1 --- 2 --- 3");
  printf("\n------------------");
  for(int i = 0; i < 5; i++)
  {
    char cubo1, cubo2, cubo3;
    consultar_topo_pilha(tubo1a, &cubo1);
    consultar_topo_pilha(tubo2a, &cubo2);
    consultar_topo_pilha(tubo3a, &cubo3);
    printf("\n| %c |   | %c |   | %c |", cubo1, cubo2, cubo3);

    desempilhar(tubo1a);
    desempilhar(tubo2a);
    desempilhar(tubo3a);
  }
  printf("\n------------------");


  // printf de todos os tubos com os valores

  /*
  ---------------
  1     2     3
  ---------------
  |U|   | |   | |
  |O|   | |   | |
  |I|   | |   | |
  |E|   | |   | |
  |A|   | |   | |
  ---------------
  */

  return 1; // 1- true || 0 - false
}

int movimentarCubo(Pilha *origem, Pilha *destino)
{
  char cubo;
  consultar_topo_pilha(origem, &cubo);
  desempilhar(origem);
  empilhar(destino, cubo);
  
  return 1;
}

Pilha* criarTubo(int vazio){
  Pilha *tubo = criar_pilha();
  if(vazio) {

    empilhar(tubo, ' ');
    empilhar(tubo, ' ');
    empilhar(tubo, ' ');
    empilhar(tubo, ' ');
    empilhar(tubo, ' ');

    return tubo;
  }


  empilhar(tubo, 'U');
  empilhar(tubo, 'O');
  empilhar(tubo, 'I');
  empilhar(tubo, 'E');
  empilhar(tubo, 'A');

  return tubo;
}

int liberarTubo(Pilha *tubo1, Pilha *tubo2, Pilha *tubo3)
{
  liberar_pilha(tubo1);
  liberar_pilha(tubo2);
  liberar_pilha(tubo3);
  
  return 1;
}