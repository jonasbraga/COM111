// Comando para compilar e executar
// gcc ./Codigos/lista_3/main.c ./Codigos/lista_3/listaEncadeada.h ./Codigos/lista_3/listaEncadeada.c -o exe -lm && ./exe

// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "listaEncadeada.h"


Aluno* criar_dado();
int preencher_nova_lista(Lista *l2);

// funcao principal
int main(void) {

  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Lista *li = NULL, *l2 = NULL, *l3 = NULL;
  Aluno *aluno;
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

        if(li == NULL){
          printf("\n Lista não criada!");
          break;
        }

        printf("\n Lista criada com sucesso!");
        break;

      case 2:

        // liberar lista
        if(!liberar_lista(li)){
          printf("\n Lista não liberada!");
          break;
        }

        printf("\n Lista liberada com sucesso!");
        break;

      case 3:

        // inserir elemento no início
        aluno = criar_dado();
        if(!inserir_lista_inicio(li, aluno)){
          printf("\n Falha na inserção!");
          break;
        }

        printf("\n Inserção realizada com sucesso!");
        break;

      case 4:

        // inserir elemento no final
        aluno = criar_dado();
        if(!inserir_lista_final(li, aluno)){
          printf("\n Falha na inserção!");
          break;
        }
        
        printf("\n Inserção realizada com sucesso!");
        break;

      case 5:

        // inserir elemento de forma ordenada
        aluno = criar_dado();
        if(!inserir_lista_ordenada(li, aluno)){
          printf("\n Falha na inserção!");
          break;
        }
        
        printf("\n Inserção realizada com sucesso!");
        break;

      case 6:

        // remover elemento do início
        if(!remover_lista_inicio(li)){
          printf("\n Falha na remoção!");
          break;
        }

        printf("\n Remoção realizada com sucesso!");
        break;

      case 7:

        // remover elemento do final
        if(!remover_lista_final(li)){
          printf("\n Falha na remoção!");
          break;
        }

        printf("\n Remoção realizada com sucesso!");
        break;

      case 8:

        // remover elemento do meio
        printf("\n Qual a matricula do aluno a ser removido: ");
        scanf("%d", &dado);

        if(!remover_lista_meio(li, aluno)){
          printf("\n Falha na remoção!");
          break;
        }

        printf("\n Remoção realizada com sucesso!");
        break;

      case 9:

        // busca elemento pela posicao
        printf("\n Posição do elemento a ser buscado: ");
        scanf("%d", &pos);

        if(!buscar_lista_posicao(li, pos, aluno)){
          printf("\n Posição não existe!");
          break;
        }
        
        printf("\n Busca realizada com sucesso!");
        printf("\n Elemento da %dª posição: %d", pos, dado);
        break;

      case 10:

        // busca elemento pelo dado
        printf("\n Matrícula do aluno a ser buscado: ");
        scanf("%d", &dado);

        if(!buscar_lista_dado(li, dado, &pos)){
          printf("\n Elemento não encontrado!");
          break;  
        }

        printf("\n Busca realizada com sucesso!");
        printf("\n Elemento da %dª posição: %d", pos, dado);
        break;

      case 11:

        // imprime a lista
        printf("\n Lista encadeada: ");
        if(!imprimir_lista(li)){
          printf("\n Lista não encontrada!");
        }
        

        break;

      case 12:

        // concatena duas listas
        l2 = criar_lista();
        l3 = criar_lista();
        
        if(l2 == NULL){
          printf("\n Lista não criada!");
          break;
        }

        if(!preencher_nova_lista(l2)){
          printf("\n Falha ao preencher nova lista!");
          break;
        }

        printf("\nConcatenando listas... ");
        
        if(!merge_listas(li, l2, l3)){
          printf("\n Falha na concatenação!");
          break;
        }

        printf("\n Lista concatenada: \n");

        if(!imprimir_lista(l3)) printf("Erro ao imprimir lista 3.");       
        break;

      case 13:

        // Remove matriculas repetidas da lista
        printf("\nCriando cópia da lista sem matriculas repetidas...");

        l2 = criar_lista();

        ok = remove_duplicate_matriculas(li, l2);
        if(ok){
          printf("\n Lista sem matrículas repetidas: ");
          imprimir_lista(l2);
        }else if(ok == -1){
          printf("\n A lista orginal não possui matrículas repetidas, nenhuma alteração foi realizada.");
        }else{
          printf("\n Falha ao remover matrículas repetidas!");
        }

        break;

      case 14:

        
        // Inverte a lista
        printf("\nInvertendo lista... ");
        
        l2 = criar_lista();
        
        if(l2 == NULL){
          printf("\n Lista não criada!");
          break;
        }

        if(!inverte_lista(li, l2)){
          printf("\n Falha na inversão!");
          break;
        }

        printf("\n Lista invertida: \n");
        imprimir_lista(l2);
        break;

      case 15:

        // Verifica se a lista está ordenada
        printf("\nVerificando ordenação da lista... ");
        ok = verifica_ordem_lista(li);
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
        printf("\nVerificando tamanho da lista... ");
        int tamanho = tamanho_lista(li);
        printf("\nA lista possui %d elementos", tamanho);
        break;
        
      case 17:

        // libera memória e finaliza programa
        liberar_lista(li);
        printf("\nFinalizando...\n");
        break;

      default:
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 17);

  return 0;
}


int preencher_nova_lista(Lista *l2){
  int ok = 0, mais_elementos = 1;

  printf("\nPor favor, preencha a nova lista: ");
  while(mais_elementos){

    if (!inserir_lista_final(l2, criar_dado())) return 0;

    printf("\nDeseja inserir mais elementos na lista? (1 - Sim | 0 - Não)\n");
    scanf("%d", &mais_elementos);
  }

  return 1;
}

Aluno* criar_dado()
{
  char nome[30];
  int matricula;
  float nota;

  printf("\nDigite o nome do aluno: ");
  scanf("%s", nome);

  printf("\nDigite a matrícula do aluno: ");
  scanf("%d", &matricula);

  printf("\nDigite a nota do aluno: ");
  scanf("%f", &nota);

  return criar_aluno(matricula, nome, nota);;
}
