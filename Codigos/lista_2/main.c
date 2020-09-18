// https://repl.it/@elisa_rodrigues/Modulo4-TAD-Ponto#ponto.h
// https://pt.khanacademy.org/math/algebra2/introduction-to-complex-numbers-algebra-2/the-imaginary-numbers-algebra-2/a/intro-to-the-imaginary-numbers

#include <stdio.h>
#include "complex.h"

int main(void) {

  Complex *nc1, *nc2, *r; // necessário declarar ponteiros para acessar a TAD

  // cria dois numeros complexos: nc1 e nc2
  nc1 = complexCriar(10, 21);
  nc2 = complexCriar(7, 25);

  // Operações com números complexos

  // Soma
  printf("\nSoma entre números complexos:\n");
  complexImprimir(nc1);
  printf(" + ");
  complexImprimir(nc2);
  printf(" = ");
  r = complexSomar(nc1, nc2);
  complexImprimir(r);
  printf("\n");

  // Subtração
  printf("\nSubtração entre números complexos:\n");
  complexImprimir(nc1);
  printf(" - ");
  complexImprimir(nc2);
  printf(" = ");
  r = complexSubtrair(nc1, nc2);
  complexImprimir(r);
  printf("\n");
 
  // Divisão
  printf("\nDivisão entre números complexos:\n");
  complexImprimir(nc1);
  printf(" / ");
  complexImprimir(nc2);
  printf(" = ");
  r = complexDividir(nc1, nc2);
  complexImprimir(r);
  printf("\n");

  // Multiplicação
  printf("\nMultiplicação entre números complexos:\n");
  complexImprimir(nc1);
  printf(" * ");
  complexImprimir(nc2);
  printf(" = ");
  r = complexMultiplicar(nc1, nc2);
  complexImprimir(r);
  printf("\n");
 
  // libera memória alocada para os pontos p e q
  complexLiberar(nc1);
  complexLiberar(nc2);
  complexLiberar(r);
  
  printf("\n");
  return 0;
}