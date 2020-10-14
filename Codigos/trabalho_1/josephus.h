// TAD para Lista Dinâmica Encadeada Circular

#ifndef _LISTA_DEC
#define _LISTA_DEC

typedef struct elemento* Lista;

typedef struct soldado Soldado;

// funções para alocar e desalocar memória
Lista* criar_lista();
int liberar_lista(Lista *li);

// funções para obter informações da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li, char nome[]);
int inserir_lista_final(Lista *li, char nome[]);
int inserir_lista_ordenada(Lista *li, char nome[]);

// funções para remoção de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, int codigo);

// funções para buscar elementos na lista
int buscar_lista_posicao(Lista *li, int pos, int *dado);
int buscar_lista_dado(Lista *li, int dado, int *pos);

int imprimir_lista(Lista *li);

#endif