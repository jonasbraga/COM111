#include<stdio.h>
#include<stdlib.h>

void fillArray(int l, int c, int *v);
void fillMatrix(int l, int c,int *v, int **m);
void showArray(int l, int c, int *v);
void showMatrix(int l, int c, int *v, int **m);

int main() {

  int l, c, *v, **m, i;

  printf("Insira a quantidade de linhas: ");
  scanf("%d", &l);

  printf("Insira a quantidade de colunas: ");
  scanf("%d", &c);

  v = (int*) malloc(l*c * sizeof(int));
  m = (int**) malloc(l * sizeof(int*));
  
  for(i = 0; i < l; i++){
    m[i] = (int*) malloc(c * sizeof(int));
  }

  fillArray(l, c, v);
  showArray(l, c, v);
  printf("\n");

  fillMatrix(l, c, v, m);
  showMatrix(l, c, v, m);
  printf("\n");

  free(v);

  for(i=0; i<l; i++) {
    free(m[i]);
  }

  free(m);

  return 0;
}

void fillArray(int l, int c, int *v) {
  
  int i;
  
  printf("Insira os valores do vetor: ");
  
  for(i=0; i<l*c; i++) {
    scanf("%d", &v[i]);
  }
}

void fillMatrix(int l, int c,int *v, int **m) {

  int i, j, z = 0;

  for(i=0; i<l; i++) {
    for(j=0; j<c; j++) {
      m[i][j] = v[z];
      z++;
    }
  }
}

void showArray(int l, int c, int *v) {

  int i;

  printf("Vetor: \n");

  for (i=0; i<c*l; i++) {
    printf("%d", v[i]);
  }
  printf("\n");
}

void showMatrix(int l, int c, int *v, int **m) {

  int i, j;
  
  printf("Matriz: \n");

  for(i=0; i<l; i++) {
    for(j=0; j<c; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}