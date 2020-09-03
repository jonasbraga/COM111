#include<stdio.h>
#include<stdlib.h>

const float APPROVED_AVERAGE = 6.0;

struct Aluno {
  int matricula;
  char nome [50];
  int dia_nasc;
  int mes_nasc;
  int ano_nasc;
  float nota;
};

typedef struct Aluno ALUNO;

ALUNO* createStudentsArray(int n);
void showApprovedStudents(int n, ALUNO *alunos);
void fillStudents(int n, ALUNO *alunos);
void showApprovedStudents(int n, ALUNO *alunos);
void fillStudentData(ALUNO *aluno);
void showStudentData(ALUNO aluno);

int main(){
  int n;
  ALUNO *alunos;

  printf("Insira o numero de alunos: ");
  scanf("%d", &n);
 
  alunos = createStudentsArray(n);

  fillStudents(n, alunos);

  showApprovedStudents(n, alunos);

  return 0;
}

// Aloca um espaço dinamico na memoria para os alunos
ALUNO* createStudentsArray(int n) {

  ALUNO *alunos = malloc(n * sizeof(ALUNO));
  return alunos;
}

void fillStudents(int n, ALUNO *alunos) {

  for(int i = 0;i < n; i++){
    printf("\n%dº aluno: \n", i+1);
    fillStudentData(&alunos[i]);   
    printf("\n");
  }
}

// Mostra os alunos aprovados (nota>=6)
void showApprovedStudents(int n, ALUNO *alunos) {

  printf("\n==== ALUNOS APROVADOS ====\n");

  for(int i = 0;i < n; i++){
    if(alunos[i].nota < APPROVED_AVERAGE) continue;
    printf("\n %dº aluno: \n", i+1);
    showStudentData(alunos[i]);
    printf("\n");
  }
}

// Pede os dados do aluno para o usuário e salva
void fillStudentData(ALUNO *aluno) {
  printf("Matricula: ");
  scanf("%d", &aluno->matricula);

  printf("Nome: ");
  scanf(" %[^\n]s", aluno->nome);

  printf("Dia de nascimento: ");
  scanf(" %d", &aluno->dia_nasc);

  printf("Mês de nascimento: ");
  scanf("%d", &aluno->mes_nasc);

  printf("Ano de nascimento: ");
  scanf("%d", &aluno->ano_nasc);

  printf("Nota: ");
  scanf("%f", &aluno->nota);
}

// Mostra um aluno
void showStudentData(ALUNO aluno) {
  printf("\nMatricula: %d", aluno.matricula);
  printf("\nNome: %s", aluno.nome);
  printf("\nDia de nascimento: %d", aluno.dia_nasc);
  printf("\nMês de nascimento: %d", aluno.mes_nasc);
  printf("\nAno de nascimento: %d", aluno.ano_nasc);
  printf("\nNota: %0.2f", aluno.nota);
}