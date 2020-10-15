// TAD para Lista Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#ifndef _LISTA_ENCADEADA
#define _LISTA_ENCADEADA

//typedef struct elemento* Lista;
typedef struct elemento* Lista;
typedef struct aluno Aluno;

// funções para alocar e desalocar memória
Aluno* criar_aluno();

// funções para alocar e desalocar memória
Lista* criar_lista();
int liberar_lista(Lista *li);	

// funções para obter informações da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li, Aluno dado);
int inserir_lista_final(Lista *li, Aluno dado);
int inserir_lista_ordenada(Lista *li, Aluno dado);

// funções para remoção de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, Aluno dado);

// funções para buscar elementos na lista
int buscar_lista_posicao(Lista *li, int pos, Aluno *dado);
int buscar_lista_dado(Lista *li, int dado, int *pos);

int imprimir_lista(Lista *li);

// Novas funções adicionadas
int merge_listas(Lista *li, Lista *l2, Lista *l3);
int remove_duplicate_matriculas(Lista *li, Lista *l2);
int inverte_lista(Lista *li, Lista *l2);
int verifica_ordem_lista(Lista *li);
int verifica_tamanho_lista(Lista *li, int *tamanho);

#endif