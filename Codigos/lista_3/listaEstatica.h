
// TAD para Lista Estática baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#ifndef _LISTA_ESTATICA
#define _LISTA_ESTATICA

typedef struct lista Lista;

// funções para alocar e desalocar memória
Lista* criar_lista();
int liberar_lista(Lista *li);

// funções para obter informações da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li, int dado);
int inserir_lista_final(Lista *li, int dado);
int inserir_lista_ordenada(Lista *li, int dado);

// funções para remoção de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, int codigo);

// funções para buscar elementos na lista
int buscar_lista_posicao(Lista *li, int pos, int *dado);
int buscar_lista_dado(Lista *li, int dado, int *pos);

int imprimir_lista(Lista *li);

// Novas funções adicionadas
int merge_listas(Lista *li, Lista *l2, Lista *l3);
int remove_duplicate_matriculas(Lista *li, Lista *l2);
int inverte_lista(Lista *li, Lista *l2);
int is_list_sorted(Lista *li);
int get_list_size(Lista *li, int *tamanho);

#endif