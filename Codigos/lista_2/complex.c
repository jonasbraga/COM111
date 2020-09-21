#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define os protótipos das funções
#include "complex.h"

// --------------------------
// definição de structs 
// --------------------------

struct complex {
  float nReal;
  float nImaginario;
};

// --------------------------
// implementação das funções 
// --------------------------

// função para criar um novo numero complexo
Complex* complexCriar(float a, float b){

  Complex* nc = (Complex*) malloc(sizeof(Complex));

  if(nc != NULL){
    nc->nReal = a;
    nc->nImaginario = b;
  }
  
  return nc;
}

// função para somar 2 números complex
void complexSomar(Complex* nc1, Complex* nc2, Complex* result){
  
  // (a + c)
  result->nReal = (nc1->nReal + nc2->nReal);
  
  // (b + d)i
  result->nImaginario = (nc1->nImaginario + nc2->nImaginario);
}

// função para subtrair 2 números complexos
void complexSubtrair(Complex* nc1, Complex* nc2, Complex* result){
  
   // (a - c)
  result->nReal = (nc1->nReal - nc2->nReal);
  
  // (b - d)i
  result->nImaginario = (nc1->nImaginario - nc2->nImaginario);
}

// função para multiplicar 2 números complexos
void complexMultiplicar(Complex* nc1, Complex* nc2, Complex* result){
  
  //  (ac − bd)
  result->nReal = ((nc1->nReal*nc2->nReal) - (nc1->nImaginario*nc2->nImaginario));

  // (bc + ad)i
  result->nImaginario = ((nc1->nImaginario*nc1->nReal) + (nc1->nReal*nc2->nImaginario));
}

// função para dividir 2 números complexos
void complexDividir(Complex* nc1, Complex* nc2, Complex* result){
  
  // ((ac + bd)/(c2 + d2)) + ((bc − ad)/(c2 + d2))i

  // ((ac + bd)/(c^2 + d^2))
  result->nReal = (((nc1->nReal*nc2->nReal) + (nc1->nImaginario*nc2->nImaginario))/((nc2->nReal*nc2->nReal) + (nc2->nImaginario*nc2->nImaginario)));

  // ((bc − ad)/(c^2 + d^2))i
  result->nImaginario = ((nc1->nImaginario*nc2->nReal) - (nc2->nReal*nc2->nReal + nc2->nImaginario*nc2->nImaginario));
}

// função para imprimir o numero complexo
void complexImprimir(Complex* nc){
  printf("(%0.1f + %0.1fi)", nc->nReal, nc->nImaginario);  
}

// função para liberar a memória de um numero complexo
void complexLiberar(Complex* nc){
  free(nc);
}