
// TAD para Lista Estática baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>
#include "listaEstatica.h"

#define MAX 100

// definição do tipo lista
struct lista{
  int qtd;
  int dados[MAX];
};


//**************************************************************************
// função para alocar memória do tipo Lista
Lista* criar_lista()
{
  // 'li' é um ponteiro do tipo Lista
  Lista *li = (Lista*) malloc(sizeof(Lista));

  // se a alocação estiver correta qtd da lista é zero
  if(li != NULL){
    li->qtd = 0;
  }

  return li;
}


//**************************************************************************
// função para liberar memória
int liberar_lista(Lista *li)
{
  // verifica se a lista foi alocada corretamente
  if(li == NULL){
    return 0;
  }

  // libera o ponteiro (Lista)
  free(li);

  return 1;
}

//**************************************************************************
// função para obter o tamanho da lista
int tamanho_lista(Lista *li)
{
  // verifica se a lista foi alocada corretamente
  if(li == NULL){
    return -1;
  }else{
      // retorna a quantidade de elementos da lista
      return li->qtd;
  }
}

//**************************************************************************
// função para verificar se a lista está vazia
int lista_vazia(Lista *li)
{
  // verifica se houve problema na criação da lista
  // ou seja, 'li' não é uma lista válida
  if(li == NULL){
    return -1;
  }

  // verifica se a lista esta vazia
  if(li->qtd == 0){
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}


//**************************************************************************
// função para verificar se a lista está cheia
int lista_cheia(Lista *li)
{
  // verifica se houve problema na criação da lista
  // ou seja, 'li' não é uma lista válida
  if(li == NULL){
    return -1;
  }

  // verifica se a lista esta cheia
  if(li->qtd == MAX){
    return 1;
  }

  // se não estiver cheia, retorna 0
  return 0;
}



//**************************************************************************
// função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li, int dado)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

   // verifica se a lista esta cheia
  if(lista_cheia(li) == 1){
    return 0;
  }

  // movimenta todos os elementos da lista uma posição para frente
  for(int i=li->qtd-1; i>=0; i--){
    li->dados[i+1] = li->dados[i];
  }

  // insere o dado na primeira posição do vetor
  li->dados[0] = dado;

  // incrementa quantidade de elementos
  li->qtd++;

  return 1;
}


//**************************************************************************
// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li, int dado)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista esta cheia
  if(lista_cheia(li) == 1){
    return 0;
  }

  // insere o dado na posição logo após o último elemento do vetor
  li->dados[li->qtd] = dado;

  // incrementa quantidade de elementos
  li->qtd++;

  return 1;
}


//**************************************************************************
// função para inserir elemento no final da lista
int inserir_lista_ordenada(Lista *li, int dado)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista esta cheia
  if(lista_cheia(li) == 1){
    return 0;
  }

  // percorre a lista, enquanto houver elementos, e o dado da lista for menor que o dado a ser inserido
  int i = 0;
  while(i < li->qtd && li->dados[i] < dado){
    i++;
  }

  // movimenta uma posição para frente, todos os elementos que estão depois da posição i, onde o novo elemento será inserido
  for(int k=li->qtd-1; k>=i; k--){
    li->dados[k+1] = li->dados[k];
  } 

  // insere o dado na posição logo após o último elemento do vetor
  li->dados[i] = dado;

  // incrementa quantidade de elementos
  li->qtd++;

  return 1;
}

//**************************************************************************
// função para remover o elemento do início da lista
int remover_lista_inicio(Lista *li)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista esta vazia
  if(lista_vazia(li) == 1){
    return 0;
  }

  // movimenta uma posição para trás, todos os elementos depois do primeiro
  for(int k=0; k<li->qtd-1; k++){
    li->dados[k] = li->dados[k+1];
  } 

  li->qtd--;

  return 1;
}

//**************************************************************************
// função para remover o elemento do final da lista
int remover_lista_final(Lista *li)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista esta vazia
  if(lista_vazia(li) == 1){
    return 0;
  }

  li->qtd--;

  return 1;

}

//**************************************************************************
// função para remover um elemento específico
int remover_lista_meio(Lista *li, int dado)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista esta vazia
  if(lista_vazia(li) == 1){
    return 0;
  }

  // percorre a lista, enquanto houver elementos, e o dado da lista for diferente que o dado a ser removido
  int i = 0;
  while(i < li->qtd && li->dados[i] != dado){
    i++;
  }

  // elemento não existe na lista
  if(i == li->qtd){
    return 0;
  }

  // movimenta uma posição para trás, todos os elementos que estão depois da posição i, onde o elemento foi removido
  for(int k=i; k<=li->qtd-1; k++){
    li->dados[k] = li->dados[k+1];
  } 

  li->qtd--;

  return 1;
}



//**************************************************************************
// função para imprimir a lista estática
int imprimir_lista(Lista *li)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  for(int i=0; i<li->qtd; i++){
    printf("%d ", li->dados[i]);
  }

  return 1;
}


int buscar_lista_posicao(Lista *li, int pos, int *dado)
{
  // verifica se a lista foi criada corretamente e se a posição é válida (note que é a posição na lista e não o índice do vetor)
  if(li == NULL || pos <= 0 || pos > li->qtd){
    return 0;
  }

  // copia o dado da posição desejada (parâmetro passado por referência)
  *dado = li->dados[pos-1];

  return 1;
}


int buscar_lista_dado(Lista *li, int dado, int *pos)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // procura a posição no vetor onde o dado desejado se encontra
  int i = 0;
  while(i < li->qtd && li->dados[i] != dado){
    i++;
  }

  // verifica se elemento não foi encontrado 
  if(i == li->qtd){ 
    return 0;
  }

  // copia a posição da lista onde o dado foi encontrado (parâmetro passado por referência)
  *pos = i+1; 

  return 1;
}

//**************************************************************************
// Novas funções adicionadas
int merge_listas(Lista *li, Lista *l2, Lista *l3)
{
  // verifica se as listas existem
  if(li == NULL || l2 == NULL || l3 == NULL){
    return 0;
  }

  // procura a posição no vetor onde o dado desejado se encontra
  int i = 0;

  for(int i = 0; i < li->qtd; i++){
    l3->dados[i] = li->dados[i];
    l3->qtd++;
  }

  for(int i = 0; i < l2->qtd; i++){
    l3->dados[l3->qtd] = l2->dados[i];
    l3->qtd++;
  }

  return 1;  
}

int remove_duplicate_matriculas(Lista *li, Lista *l2){

  int insert;
  for(int i = 0; i < li->qtd; i++){
    insert = 1;
    
    for(int j = 0; j < l2->qtd; j++) {
      if(li->dados[i] == l2->dados[j]) {
        insert = 0;
        break;
      }
    }
    
    if (!insert) continue;
    l2->dados[l2->qtd] = li->dados[i];
    l2->qtd++;
  }
  
  return 1;  
}

int inverte_lista(Lista *li, Lista *l2){

  for(int i = li->qtd; i >= 0; --i){
    l2->dados[l2->qtd] = li->dados[i];
    l2->qtd++;
  }

  return 1;  
}

int verifica_ordem_lista(Lista *li){

  int crescente = 1, decrescente = 1;
  
  for(int i = 0; i < li->qtd - 1; i++){
    if(li->dados[i] >= li->dados[i + 1]){
      crescente = 0;
      break;
    }
  }

  for(int i = 0; i < li->qtd - 1; i++){
    if(li->dados[i] <= li->dados[i + 1]){
      decrescente = 0;
      break;
    } 
  }

  return (int) (crescente || decrescente);  
}

int verifica_tamanho_lista(Lista *li, int *tamanho){


  return 1;
}
