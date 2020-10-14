// Comando para compilar e executar
// gcc ./Codigos/trabalho_1/main.c ./Codigos/trabalho_1/josephus.h ./Codigos/trabalho_1/josephus.c -o exe -lm && ./exe

// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bibliotecas do projeto
#include "josephus.h"

const char FILEPATH[] = "/home/runner/COM111/Codigos/trabalho_1/soldados.txt";
const char SPLIT_DELIMITER = '\n';

void showMenu();
void showSoldiers();
void clearBuffer();
void clearScreen();
void solveProblem();
int insertSoldierList();

Lista *li;

// funcao principal
int main() {
  showMenu();

  return 0; 
}

// ----- função para gerar o menu principal ----- //
void showMenu(){
  char option = ' ';

  clearScreen();
  printf("\n=========================================");
  printf("\n========= PROBLEMA DE JOSEPHUS  =========");
  printf("\n=========================================");
  printf("\n==                                     ==");
  printf("\n==                                     ==");
  printf("\n==             RESOLVER  (1)           ==");
  printf("\n==             SOLDADOS  (2)           ==");
  printf("\n==               SAIR    (3)           ==");
  printf("\n==                                     ==");
  printf("\n==                                     ==");
  printf("\n=========================================\n");

  clearBuffer();
  scanf("%c", &option);
  
  if(option == '1'){
    solveProblem();
  }else if(option == '2'){
    showSoldiers();
  }
}

void solveProblem(){
  
}

int openSoldierFile(FILE *soldiersFile){
  
  soldiersFile = fopen(FILEPATH, "r");
  
  if(soldiersFile != NULL) return 1;

  printf("Não foi possível abrir o arquivo");

  return 0;
}

void showSoldiers(){
  FILE *soldiersFile;

  if(!openSoldierFile(soldiersFile)) return;

  char soldier[100] = "";

  printf("\n========================================\n");
  printf("\t\t\t\tSOLDADOS");
  printf("\n========================================\n");
  
  while(fgets(soldier, 100, soldiersFile)){
    char *username = strtok(soldier, &SPLIT_DELIMITER);
    printf("\t\t\t\t %s\n", username);
  }

  printf("\n\t\tAperte x para voltar ao menu...\n");
  printf("========================================\n");

  fclose(soldiersFile);
  
  clearBuffer();
  while(getchar() != 'x');
  showMenu();
}

int insertSoldierList(){
  FILE *soldiersFile;

  if(!openSoldierFile(soldiersFile)) return 0;

  char soldier[100] = "";
  while(fgets(soldier, 100, soldiersFile))
    inserir_lista_final(li, strtok(soldier, &SPLIT_DELIMITER));
  
  fclose(soldiersFile);
  
  return 1; 
}

// ----- função para limpar a tela ----- //
void clearScreen(){
  system("clear");
}

// ----- função para limpar o buffer ----- //
void clearBuffer(){
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}