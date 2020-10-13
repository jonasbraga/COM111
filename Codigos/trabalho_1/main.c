// Comando para compilar e executar
// gcc ./Codigos/trabalho_1/main.c ./Codigos/trabalho_1/example.h ./Codigos/trabalho_1/example.c -o exe -lm && ./exe

// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bibliotecas do projeto
#include "example.h"

const char FILEPATH[] = "/home/runner/COM111/Codigos/trabalho_1/soldados.txt";
const char SPLIT_DELIMITER = '\n';

void showMenu();
void showSoldiers();
void clearBuffer();
void clearScreen();
void solveProblem();

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

void showSoldiers(){
  clearScreen();
  
  char soldiers[] = {};
  getSoldiers(soldiers);
  
}

int getSoldiers(char soldiers[]){
  FILE *soldiersFile;
  soldiersFile = fopen(FILEPATH, "r");

  if(soldiersFile == NULL){
    printf("Não foi possível abrir o arquivo");
    return 0;
  } 

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
  while(getchar()!='x');
  showMenu();
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