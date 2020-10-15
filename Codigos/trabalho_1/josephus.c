#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "josephus.h"

// definição do struct elemento
typedef struct soldado{
  int posicao;
  char nome[100];
} Soldado;

typedef struct elemento{
  Soldado *dado;
  struct elemento *prox;
} Elemento;


int matar_proximo_soldado(Lista *li, int id){
  /* 
   * Recebe o numero ou id do soldado atual e remove o proximo à sua direita
   * Essa função pode ser chamada do main, em um loop, até q reste somente 1
   */
}

int insert_soldier(Lista *li, int id, char nome[]){
  
}

int print_soldier(Lista *li, int id){

}

//**************************************************************************
// função para alocar memória do tipo Lista
Lista* criar_lista()
{
  // 'li' é um ponteiro para ponteiro do tipo Elemento
  Lista *li = (Lista*) malloc(sizeof(Lista));  

  // se a alocação estiver correta 'li' aponta para NULL (lista vazia)
  if(li != NULL){
    *li = NULL;
  }else{
    return NULL;
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

  // verifica se a lista não está vazia
  if((*li) != NULL){
    Elemento *no, *aux;
    no = *li;

    // laço percorre a lista até o último elemento, liberando o anterior
    while( no->prox !=  (*li) ){
      aux = no;
      no = no-> prox;
      free(aux);
    }

    // libera o último elemento
    free(no);

    // libera o ponteiro de ponteiro (Lista)
    free(li);   
  }

  return 1;
}

//**************************************************************************
// função para obter o tamanho da lista
int tamanho_lista(Lista *li)
{
  // verifica se a lista foi alocada corretamente ou se a lista está vazia
  if(li == NULL || (*li) == NULL){
    return 0;
  }

  // inicializa o contador de elementos
  int cont = 0;

  // cria um ponteiro do tipo Elemento que aponta para o primeiro elemento da lista 
  Elemento *no;  
  no = *li;

  // incrementa 'cont' até acabar o último elemento da lista
  do{
    cont++;
    no = no->prox;
  }while(no != (*li));

  // retorna a quantidade de elementos da lista
  return cont;
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

  // verifica se a lista foi criada corretamente
  // mas não contém nenhum valor (lista vazia)
  if(*li == NULL){
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}


//**************************************************************************
// função para alocar memória do tipo Elemento
Elemento* criar_elemento()
{
  // 'no' é um ponteiro do tipo Elemento
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));  

  // verifica se a memória foi alocada corretamente
  if(no == NULL){
    return 0;
  }  

  // retorna ponteiro alocado
  return no;
}

//**************************************************************************
// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li, char *nome)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL) return 0;
 
  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele na lista)
  Elemento *no;
  no = criar_elemento();

  Soldado *soldado = (Soldado*) malloc(sizeof(Soldado));

  if(soldado == NULL) return 0;
  
  soldado->posicao = tamanho_lista(li) + 1;
  strcpy(soldado->nome, nome);

  // atribui valores ao elemento novo
  no->dado = soldado;
  
  // verifica se a lista está vazia
  if((*li) == NULL){

    // insere elemento único no início da lista 
    no->prox = no;  // próximo elemento na lista circular é ele mesmo
    *li = no;       // 'no' passa a ser o primeiro elemento da lista

  }else{

    Elemento *aux;
    aux = *li;

    // percorre a lista até o último elemento
    while(aux->prox != (*li)){
      aux = aux->prox;
    }

    // insere elemento no final da lista 
    aux->prox = no;  // 'no' é o próximo elemento na lista circular após o último
    no->prox = *li;  // primeiro elemento '*li' é o próximo após o 'no'
  }

  return 1;
}

//**************************************************************************
// função para remover elemento do meio da lista
int remover_lista_meio(Lista *li, int dado)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista está vazia (não existem elementos a serem removidos)
  if((*li) == NULL){
    return 0;
  }

  Elemento *no;
  no = *li;

  // elemento a ser removido está no início da lista
  if(no->dado->posicao == dado){

    // verifica se existe apenas um elemento na lista (após remoção a lista fica vazia)
    if (no->prox == no){

      // indica que a lista ficou vazia e remove o 'no'      
      *li = NULL;
      free(no);

      // libera Elemento 'no'
      return 1;

    // remove o primeiro elemento
    }else{

      Elemento *ultimo;
      ultimo = *li;

      // percorre a lista até o último elemento
      while(ultimo->prox != (*li)){
        ultimo = ultimo->prox;
      }  
      
      // remove primeiro elemento 'no' (no = *li)
      ultimo->prox = no->prox;
      *li = no->prox;

      // libera Elemento 'no'
      free(no);

      return 1;      
    }

  }

  Elemento *anterior;
  anterior = no;
  no = no->prox; 

  // percorre a lista até achar o elemento a ser removido, ou até encontrar o primeiro elemento
  while(no != (*li) && no->dado->posicao != dado){
    anterior = no;
    no = no->prox;
  }

  // elemento a ser removido não foi encontrado
  if(no == (*li)){
    return 0;
  }

  // remove o elemento 'no'
  anterior->prox = no->prox;  // 'no->prox' passa a ser o próximo elemento na lista circular após o 'anterior'

  // libera Elemento 'no'
  free(no);

  return 1;
}

// função para buscar o elemento "dado"
int buscar_lista_dado(Lista *li, int dado, int *pos)
{
  // verifica se a lista foi criada corretamente ou se está vazia
  if(li == NULL || (*li) == NULL){
    return 0;  
  }

  Elemento *no = *li;
  int i = 1;

  // percorre a lista até achar o elemento desejado, ou até encontrar o último elemento
  while( no->prox != (*li) && no->dado->posicao != dado){
    no = no->prox;
    i++;
  }

  // verifica se dado procurado existe na lista
  if(no->dado->posicao != dado){
    return 0;

  }else{
    // copia a posição da lista onde o dado foi encontrado (parâmetro passado por referência)
    *pos = i; 
    return 1;
  }
}

int imprimir_lista(Lista *li)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  if((*li) == NULL){
    printf(" Lista vazia!");
  }

  // imprime primeiro elemento
  Elemento *no;
  no = (*li);

  // percorre lista até o último elemento
  while(no->prox != (*li)){
    printf("\n %dº - %s", no->dado->posicao, no->dado->nome);
    no = no->prox;
  }

  // imprime último elemento
  printf("\n %dº - %s \n", no->dado->posicao, no->dado->nome);
  
  return 1;
}