// Comando para compilar e executar
// gcc ./Codigos/lista_2/main.c ./Codigos/lista_2/complex.h ./Codigos/lista_2/complex.c -o exe -lm && ./exe 

#include <stdio.h>
#include "complex.h"

int main(void) {

  Complex *nc1, *nc2, *r; // Necessário declarar ponteiros para acessar a TAD

  float a = 0, b = 0, c = 0, d = 0;

  printf("Insira os valores a & b para o 1º numero complexo: ");
  scanf("%f %f", &a, &b);

  printf("Insira os valores c & d para o 2º numero complexo: ");
  scanf("%f %f", &c, &d);
  // Cria dois numeros complexos: nc1 e nc2
  nc1 = complexCriar(a, b);
  nc2 = complexCriar(c, d);

  // Inicializa o numero complexo de resultado
  r = complexCriar(0, 0);

  // Soma
  printf("\nSoma entre números complexos:\n");
  complexImprimir(nc1);
  printf(" + ");
  complexImprimir(nc2);
  printf(" = ");
  complexSomar(nc1, nc2, r);
  
  complexImprimir(r);
  printf("\n");

  // Subtração
  printf("\nSubtração entre números complexos:\n");
  complexImprimir(nc1);
  printf(" - ");
  complexImprimir(nc2);
  printf(" = ");
  complexSubtrair(nc1, nc2, r);
  complexImprimir(r);
  printf("\n");
 
  // Divisão
  printf("\nDivisão entre números complexos:\n");
  complexImprimir(nc1);
  printf(" / ");
  complexImprimir(nc2);
  printf(" = ");
  complexDividir(nc1, nc2, r);
  complexImprimir(r);
  printf("\n");

  // Multiplicação
  printf("\nMultiplicação entre números complexos:\n");
  complexImprimir(nc1);
  printf(" * ");
  complexImprimir(nc2);
  printf(" = ");
  complexMultiplicar(nc1, nc2, r);
  complexImprimir(r);
  printf("\n");
  
  // libera memória alocada para os numeros nc1, nc2 e r
  complexLiberar(nc1);
  complexLiberar(nc2);
  complexLiberar(r);
  
  printf("\n");
  return 0;
}