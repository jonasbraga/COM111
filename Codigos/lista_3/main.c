// Comando para compilar e executar
// gcc ./Codigos/lista_3/main.c ./Codigos/lista_3/listaEstatica.h ./Codigos/lista_3/listaEstatica.c -o exe -lm && ./exe

// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "listaEstatica.h"


int criar_dado(int *dado);


// funcao principal
int main(void) {

  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Lista *li = NULL;
  int opcao, dado, ok, pos;

  // menu de opções para execuções de operações sobre a lista
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n3 - Inserir elemento no início");
    printf("\n4 - Inserir elemento no final");
    printf("\n5 - Inserir elemento (ordenado)");
    printf("\n6 - Remover elemento do início");
    printf("\n7 - Remover elemento do final");
    printf("\n8 - Remover elemento (qualquer)");
    printf("\n9 - Buscar elemento pela posição");
    printf("\n10 - Buscar elemento pelo dado");
    printf("\n11 - Imprimir lista");
    printf("\n12 - Concatenar listas");
    printf("\n13 - Remover valores repetidos");
    printf("\n14 - Inverter lista");
    printf("\n15 - Verificar se lista está ordenada");
    printf("\n16 - Tamanho da lista encadeada");
    printf("\n17 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:

        // criar lista
        li = criar_lista();

        if(li != NULL){
          printf("\n Lista criada com sucesso!");
        }else{
          printf("\n Lista não criada!");
        }
        break;


      case 2:

        // liberar lista
        ok = liberar_lista(li);

        if(ok){
          printf("\n Lista liberada com sucesso!");
        }else{
          printf("\n Lista não liberada!");
        }
        break;

      case 3:

        // inserir elemento no início
        ok = criar_dado(&dado);
        ok = inserir_lista_inicio(li, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 4:

        // inserir elemento no final
        ok = criar_dado(&dado);
        ok = inserir_lista_final(li, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 5:

        // inserir elemento de forma ordenada
        ok = criar_dado(&dado);
        ok = inserir_lista_ordenada(li, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 6:

        // remover elemento do início
        ok = remover_lista_inicio(li);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 7:

        // remover elemento do final
        ok = remover_lista_final(li);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 8:

        // remover elemento do meio
        printf("\n Código do produto a ser removido: ");
        scanf("%d", &dado);

        ok = remover_lista_meio(li, dado);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 9:

        // busca elemento pela posicao
        printf("\n Posição do elemento a ser buscado: ");
        scanf("%d", &pos);

        ok = buscar_lista_posicao(li, pos, &dado);

        if(ok){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento da %dª posição: ", pos);
          printf("%d", dado);
        }else{
          printf("\n Posição não existe!");
        }

        break;

      case 10:

        // busca elemento pelo dado
        printf("\n Código do produto a ser buscado: ");
        scanf("%d", &dado);

        ok = buscar_lista_dado(li, dado, &pos);

        if(ok){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento da %dª posição: ", pos);
          printf("%d", dado);
        }else{
          printf("\n Elemento não encontrado!");
        }

        break;

      case 11:

        // imprime a lista
        printf("\n Lista estática: ");
        ok = imprimir_lista(li);

        break;

      case 12:

        // concatena duas listas
        printf("\n Concatenando listas... ");
        ok = merge_listas(li, l2, l3);
        if(ok){
          printf("\n Lista concatenada: ");
          ok = imprimir_lista(l3);
        }else{
          printf("\n Falha na concatenação!");
        }

        break;

      case 13:

        // Remove matriculas repetidas da lista
        printf("\n Criando cópia da lista sem matriculas repetidas...");
        ok = remove_duplicate_matriculas(li, l2);
        if(ok){
          printf("\n Lista sem matrículas repetidas: ");
          ok = imprimir_lista(l2);
        }else if(ok == -1){
          printf("\n A lista orginal não possui matrículas repetidas, nenhuma alteração foi realizada.");
        }else{
          printf("\n Falha ao remover matrículas repetidas!");
        }

        break;

      case 14:

        // Inverte a lista
        printf("\n Invertendo lista... ");
        ok = inverte_lista(li, l2);
        if(ok){
          printf("\n Lista invertida: ");
          ok = imprimir_lista(l2);
        }else{
          printf("\n Falha na inversao!");
        }

        break;

      case 15:

        // Verifica se a lista está ordenada
        printf("\n Verificando ordenação da lista... ");
        ok = is_list_sorted(li);
        if(ok){
          printf("\n Lista ordenada");
        }else if(ok == 0){
          printf("\n Lista não ordenada!");
        }else{
          printf("\n Falha na verificação da ordenação!");
        }

        break;

      case 16:

        // Verifica o tamanho da lista encadeada
        printf("\n Verificando tamanho da lista... ");
        ok = get_list_size(li, &tamanho);
        if(ok){
          printf("\n A lista possui %d elementos", tamanho);
        }else{
          printf("\n Falha na verificação do tamanho da lista!");
        }

        break;
        
      case 17:

        // libera memória e finaliza programa
        liberar_lista(li);
        printf("\nFinalizando...");
        break;

      default:
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 12);

  return 0;
}





int criar_dado(int *dado)
{
    printf("\nDigite um valor: ");
    scanf("%d", dado);

    return 1;
}