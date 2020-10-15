// TAD para Lista Dinâmica Encadeada Circular

#ifndef _LISTA_DEC
#define _LISTA_DEC

typedef struct elemento* Lista;

typedef struct soldado Soldado;

void matar_proximo_soldado(Lista *li);
int insert_soldier(Lista *li, int id, char *nome);
int print_soldier(Lista *li, int id);

// funções para alocar e desalocar memória
Lista* criar_lista();
int liberar_lista(Lista *li);

// funções para obter informações da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

// funções para inserção de elementos da lista
int inserir_lista_final(Lista *li, char *nome);

// funções para remoção de elementos da lista
int remover_lista_meio(Lista *li, int codigo);

// funções para buscar elementos na lista
int buscar_lista_dado(Lista *li, int dado, int *pos);

int imprimir_lista(Lista *li);

#endif