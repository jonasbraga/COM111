#include<stdio.h>
#include<stdlib.h>

void fillV(int l, int c, int *v);
void fillM(int l, int c,int *v, int **m);
void showV(int l, int c, int *v);
void showM(int l, int c, int *v, int **m);

int main() {

  int l, c, *v, **m, i;

  printf("Insira o número de linhas: ");
  scanf("%d", &l);

  printf("Insira o número de colunas: ");
  scanf("%d", &c);

  v = (int*) malloc(l*c * sizeof(int));
  m = (int**) malloc(l * sizeof(int*));
  
  for(i = 0; i < l; i++){
    m[i] = (int*) malloc(c * sizeof(int));
  }

  fillV(l, c, v);
  showV(l, c, v);
  printf("\n");

  fillM(l, c, v, m);
  showM(l, c, v, m);
  printf("\n");

  free(v);

  for(i=0; i<l; i++) {
    free(m[i]);
  }

  free(m);

  return 0;
}

void fillV(int l, int c, int *v) {
  
  int i;
  
  printf("Insira os valores do vetor: ");
  
  for(i=0; i<l*c; i++) {
    scanf("%d", &v[i]);
  }
}

void fillM(int l, int c,int *v, int **m) {

  int i, j, z = 0;

  for(i=0; i<l; i++) {
    for(j=0; j<c; j++) {
      m[i][j] = v[z];
      z++;
    }
  }
}

void showV(int l, int c, int *v) {

  int i;

  printf("Vetor:");

  for (i=0; i<c*l; i++) {
    printf("%d", v[i]);
  }
  printf("\n");
}

void showM(int l, int c, int *v, int **m) {

  int i, j;
  
  printf("Matriz:");

  for(i=0; i<l; i++) {
    for(j=0; j<c; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}