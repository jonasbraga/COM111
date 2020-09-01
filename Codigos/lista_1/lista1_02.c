#include<stdio.h>
#include<stdlib.h>

struct Aluno {
  int matricula;
  char nome [50];
  int dia_nasc;
  int mes_nasc;
  int ano_nasc;
  float nota;
};

int *createStudentsArray(int n);
void fillStudents();
void showStudents();
void fillStudentData();
void showStudentData();

int main(){

  int n, *aluno;

  printf("Insira o numero de alunos: ");
  scanf("%d", &n);
  
  
  return 0;
}

// ler numero n de alunos a serem cadastrados

// função com um V[n] que retorna um *ALUNO

// preencher vetor V[n]

// mostrar alunos aprovados (nota>=6)

int* createStudentsArray(int n) {

// cria os vetores suas quantidades seus atributos do registro
  struct Aluno *alunos;
  alunos = malloc(n * sizeof(struct Aluno));
return alunos;
}

void fillStudents() {

}

void showStudents() {

}

void fillStudentData() {

}

void showStudentData() {
  
}

/*
  (a) Alocar memória dinamicamente para um vetor do tipo ALUNO.
  (b) Preencher o vetor de alunos.
  (c) Imprimir o vetor de alunos.
  (d) Preencher o registro de um aluno.
  (e) Imprimir o registro de um aluno. 
*/