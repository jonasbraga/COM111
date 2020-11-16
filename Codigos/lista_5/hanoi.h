#ifndef _PILHA
#define _PILHA

typedef struct elemento* Pilha;               

int printTubos(Pilha *tubo1, Pilha *tubo2, Pilha *tubo3);

int movimentarCubo(Pilha *origem, Pilha *destino);

int liberarTubo(Pilha *tubo1, Pilha *tubo2, Pilha *tubo3);

Pilha* criarTubo(int vazio);
#endif 