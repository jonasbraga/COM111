// Comando para compilar e executar
/* 
 gcc ./Codigos/lista_4/main.c ./Codigos/lista_4/filaEncadeada.h ./Codigos/lista_4/filaEncadeada.c ./Codigos/lista_4/filaSenhas.h ./Codigos/lista_4/filaSenhas.c -o exe -lm && ./exe
*/

// Videos fila 31 - 37
// https://youtu.be/aEfOzz_KXl8

/**
Programa para gerenciar filas de bancos através de senhas, existem 2 serviços realizados pelo banco: caixa ou negocial. Existe 2 tipos de prioridades para cada serviço: preferencial ou convencional.
[X] - Pedir o numero de senhas do dia (ex: 20)
[X] - Criar uma fila de senhas (SE) com a quantidade inserida (ex: 0 até 20)
[X] - Criar / inicializar fila de caixa preferencial    (XP)
[X] - Criar / inicializar fila de caixa convencional    (XC)
[X] - Criar / inicializar fila de negocial preferencial (NP)
[X] - Criar / inicializar fila de negocial convencional (NC)
[X] - Criar menu para o cliente retirar sua senha, solicitando:
    [X] - Tipo de atendimento (X - Caixa | N - Negocial)
    [X] - Perfil do cliente (P - Preferencial | C - Convencional)
  [X] - Remover o 1º numero disponivel de senha (da fila SE) e concatenar com os dados inseridos (ex: XP01, NC02, etc)
  [X] - Inserir na fila corresponde a senha para ser chamada posteriormente
  [X] - Imprimir toda a fila após a nova inserção
[ ] - Criar um menu para retirada das senhas pelo funcionario do banco
  [X] - O serviço (Caixa | Negocial) será sorteado aleatoriamente para retirar a senha (usar random do time.h)
  [X] - A cada 2 senhas preferenciais, 1 convencional deve ser chamada por fila
  [ ] - Remover a senha da fila e imprimi-la
[ ] - Quando todos os n atendimentos forem realizados, finalizar o programa.
[ ] - Imprimir a quantidade de atendimentos realizados de acordo com o serviço
*/

// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// bibliotecas do projeto
#include "filaSenhas.h"

// função para limpar a tela
void clearScreen(){
  system("clear");
}

// funcao principal
int main(void) {

  srand(time(NULL));

  // no início a fila está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da fila
  Fila *SE = NULL;
  Fila *XP = NULL;
  Fila *XC = NULL;
  Fila *NP = NULL;
  Fila *NC = NULL;

  int qnt_senhas = 0;
  
  clearScreen();

  do {
    printf("\nInsira o limite diário de atendimentos: ");
    scanf("%d", &qnt_senhas);
    if (!qnt_senhas) printf("\nPor favor, insira um valor maior que 0.\n");
  }while(!qnt_senhas);
  
  SE = criar_senhas(qnt_senhas);
  if(SE == NULL){
    printf("\nNão foi possível criar as senhas");
    return 0;
  }
   
  int opcao = 0, ok = 0, atendimentos_realizados = 0, atendimento = 0, perfil = 0;
  char servico, prioridade, senha[4], cont_pref_caixa = 0, cont_pref_negocial = 0;
      
  // menu de opções para execuções de operações sobre a fila
  do {

    printf("\n\nMenu de opções");
    printf("\n1 - Retirar senha");
    printf("\n2 - Chamar senha");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    clearScreen();

    // opção 1 - retirar senha
    if(opcao == 1){
      clearScreen();

      printf("\n\nQual tipo de atendimento você deseja?");
      printf("\n1 - Caixa");
      printf("\n2 - Negocial");
      printf("\nInsira aqui: ");
      scanf("%d", &atendimento);
      
      printf("\n\nQual o seu perfil?");
      printf("\n1 - Preferencial");
      printf("\n2 - Convencional"); 
      printf("\nInsira aqui: ");
      scanf("%d", &perfil);

      Fila **fi = NULL;

      fi = atendimento == 1 ? (perfil == 1 ? &XP : &XC) : (perfil == 1 ? &NP : &NC);
      servico = atendimento == 1 ? 'X' : 'N';
      prioridade = perfil == 1 ? 'P' : 'C';

      clearScreen();

      char num_senha[4];
      
      if(!retirar_senha(SE, num_senha)) return 0;

      if(inserir_senha_fila(fi, num_senha, servico, prioridade)){
        printf("\n Senha cadastrada com sucesso!");
      }else{
        printf("\n Fila não criada!");
      }

    // opção 2 - chamar senha
    } else if(opcao == 2) {   
      
      

      if(fila_vazia(XP) && fila_vazia(XC) && fila_vazia(NP) && fila_vazia(NC)){

        printf("\n TODAS VAZIAS");


        // Todas filas vazias

      }else{

     
        Fila **fila = NULL;
        int vazia = 0;

        //tratar se todas as filas estao vazias, se sim encerrar mostrando a quantidade de atendiemntos que cada fila realizou

        Fila **fila_sorteada = NULL;
        char fila_sorteada_txt[2] = {' ', ' '};
        do {

          int num = rand() % 2;

          printf("num: %d\n", num);

          fila_sorteada = num == 1 ? (cont_pref_caixa >= 2 ? &XC : &XP) : (cont_pref_negocial >= 2 ? &NC : &NP);
          fila_sorteada_txt[0] = num == 1 ? 'X' : 'N';
          fila_sorteada_txt[1] = (cont_pref_caixa >= 2 || cont_pref_negocial >= 2) ? 'C' : 'P';
        /* 
          if(num == 1){
            if(cont_pref_caixa >= 2){
              fila_sorteada = &XC;
              cont_pref_caixa = 0; 
            }else{
              fila_sorteada = &XP;
              cont_pref_caixa++;
            }
          }else{
            if(cont_pref_negocial >= 2){
              fila_sorteada = &NC;
              cont_pref_negocial = 0;  
            }else{
              fila_sorteada = &NP;
              cont_pref_negocial++;
            }
          }
        */
          vazia = fila_vazia(*fila_sorteada);
        } while(vazia);

        if(fila_sorteada_txt[0] == 'X'){
          cont_pref_caixa = fila_sorteada_txt[1] == 'P' ? cont_pref_caixa + 1 : 0;
        } else {
          cont_pref_negocial = fila_sorteada_txt[1] == 'P' ? cont_pref_negocial + 1 : 0;
        }

        char senha[4];

        ok = retirar_senha_fila(fila_sorteada, senha);

        if(ok == 1){
          printf("\n Senha: %s", senha);
        }else{
          printf("\n Erro!");
        } 
      }

    } else{
      printf("\nOpção inválida!");
    } 
      
  }while(!atendimentos_realizados);

  return 0;
}