// gcc ./Codigos/trabalho_1/main.c ./Codigos/trabalho_1/josephus.h ./Codigos/trabalho_1/josephus.c -o exe -lm && ./exe

// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bibliotecas do projeto
#include "josephus.h"

// caminho do arquivo com o nome dos soldados
const char FILEPATH[] = "/home/runner/COM111/Codigos/trabalho_1/soldados.txt";
const char SPLIT_DELIMITER = '\n';

void showIntro();
void showMenu();
void showSoldiers();
void clearBuffer();
void clearScreen();
void solveProblem();
int insertSoldiersList(Lista *li);
int openSoldierFile(FILE **soldiersFile);

Lista *li;

// função principal
int main() {

  li = criar_lista();

  showIntro();

  return 0; 
}

// ----- função para gerar a introdução ----- //
void showIntro(){
  clearScreen();
  printf("\n=============================================");
  printf("\n==                                         ==");
  printf("\n==   Flavius Josephus, durante o cerco     ==");
  printf("\n==  de Yodfat, estava encurralado em uma   ==");
  printf("\n==  caverna junto de 40 judeus rebeldes.   ==");
  printf("\n==                                         ==");
  printf("\n==   Ao invés de se renderem aos soldados  ==");
  printf("\n==  romanos eles optaram por outro método. ==");
  printf("\n==                                         ==");
  printf("\n==                  x para prosseguir...   ==");
  printf("\n==                                         ==");
  printf("\n=============================================\n");

  while(getchar()!='x');
  clearScreen();

  printf("\n=============================================");
  printf("\n==                                         ==");
  printf("\n==    Era um método serial de suicídio     ==");
  printf("\n==              por sorteio...             ==");
  printf("\n==                                         ==");
  printf("\n==   Josephus conseguiu restar por último  ==");
  printf("\n==     ao ficar em determinada posição e   ==");
  printf("\n==   foi capaz de se render e sobreviver.  ==");
  printf("\n==                                         ==");
  printf("\n==                  x para prosseguir...   ==");
  printf("\n==                                         ==");
  printf("\n=============================================\n");

  while(getchar()!='x');
  clearScreen();

    printf("\n=============================================");
  printf("\n==                                         ==");
  printf("\n==                                         ==");
  printf("\n==    Portanto, o problema se baseia em    ==");
  printf("\n==    descobrir qual a posição - dado o    ==");
  printf("\n==      número de pessoas e o ponto de     ==");
  printf("\n==    partida - será a última a restar     ==");
  printf("\n==         após a execução serial.         ==");
  printf("\n==                                         ==");
  printf("\n==                  x para prosseguir...   ==");
  printf("\n==                                         ==");
  printf("\n=============================================\n");

  while(getchar()!='x');
  showMenu();
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
  printf("\n==        RESOLVER PROBLEMA  (1)       ==");
  printf("\n==         MOSTRAR SOLDADOS  (2)       ==");
  printf("\n==               SAIR        (3)       ==");
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

// ----- função para realizar a eliminação de soldados ----- //
void solveProblem(){
  insertSoldiersList(li);
  printf("\n\n Soldados na lista:");
  imprimir_lista(li);
  matar_proximo_soldado(li);
}

//função para abrir a lista de soldados
int openSoldierFile(FILE **soldiersFile){
  
  *soldiersFile = fopen(FILEPATH, "r");
  
  if(*soldiersFile != NULL) return 1;

  printf("Não foi possível abrir o arquivo");

  return 0;
}

//função para mostrar a lista de soldados
void showSoldiers(){

  FILE *soldiersFile;

  if(!openSoldierFile(&soldiersFile)) return;

  clearScreen();

  char soldier[100] = "";
  int cont = 0;

  printf("\n========================================\n");
  printf("\t\t\t\tSOLDADOS");
  printf("\n========================================\n");

  while(fgets(soldier, 100, soldiersFile)){
    char *username = strtok(soldier, &SPLIT_DELIMITER);
    printf("\t\t\t   %d - %s\n", ++cont, username);
  }

  printf("\n\t\tAperte x para voltar ao menu...\n");
  printf("========================================\n");

  fclose(soldiersFile);
  
  clearBuffer();
  while(getchar() != 'x');
  showMenu();
}

//função para inserir novos soldados na lista
int insertSoldiersList(Lista *li){
  FILE *soldiersFile;

  if(!openSoldierFile(&soldiersFile)) return 0;

  char soldier[100] = "";
  while(fgets(soldier, 100, soldiersFile)){
    
    char *soldierName = strtok(soldier, &SPLIT_DELIMITER);

    printf("\n Inserindo %s\tna lista... ", soldierName);

    if(inserir_lista_final(li, soldierName)) 
      printf("Inserido");
    else 
      printf("Falhou");
  }
  
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