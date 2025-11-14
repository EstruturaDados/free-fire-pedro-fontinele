#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

/*
    Struct Item
    -----------
    Representa um item dentro da mochila do jogador.
    Armazena:
      - nome do item
      - tipo do item (arma, municao, cura, etc)
      - quantidade disponível
*/
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor global de itens da mochila
Item mochila[MAX_ITENS];
int totalItens = 0; // controla quantos itens já foram cadastrados

// ------------------------ FUNÇÕES DO SISTEMA ------------------------

/*
    inserirItem()
    -------------
    Permite cadastrar um novo item na mochila, se houver espaço.
    Utiliza totalItens como índice de inserção.
*/
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("\nA mochila esta cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    printf("\n===== CADASTRO DE ITEM =====\n");

    printf("Digite o nome do item: ");
    scanf("%s", mochila[totalItens].nome);

    printf("Digite o tipo do item (arma, municao, cura, etc): ");
    scanf("%s", mochila[totalItens].tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &mochila[totalItens].quantidade);

    totalItens++;

    printf("Item cadastrado com sucesso!\n");
}

/*
    removerItem()
    -------------
    Recebe o nome do item e o remove caso exista.
    Para remover, desloca os itens seguintes para "tampar o buraco".
*/
void removerItem() {
    char nomeRemover[30];
    int encontrado = -1;

    if (totalItens == 0) {
        printf("\nA mochila esta vazia! Nao ha itens para remover.\n");
        return;
    }

    printf("\nDigite o nome do item que deseja remover: ");
    scanf("%s", nomeRemover);

    // Busca sequencial pelo item
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Item nao encontrado!\n");
        return;
    }

    // Desloca para remover
    for (int i = encontrado; i < totalItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    totalItens--;

    printf("Item removido com sucesso!\n");
}

/*
    listarItens()
    -------------
    Exibe todos os itens cadastrados na mochila.
*/
void listarItens() {
    printf("\n===== ITENS NA MOCHILA =====\n");

    if (totalItens == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    for (int i = 0; i < totalItens; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}

/*
    buscarItem()
    -------------
    Busca sequencial pelo nome do item.
*/
void buscarItem() {
    char nomeBusca[30];
    int encontrado = -1;

    if (totalItens == 0) {
        printf("\nA mochila esta vazia! Nenhum item para buscar.\n");
        return;
    }

    printf("\nDigite o nome do item que deseja buscar: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Item nao encontrado!\n");
        return;
    }

    printf("\n===== ITEM ENCONTRADO =====\n");
    printf("Nome: %s\n", mochila[encontrado].nome);
    printf("Tipo: %s\n", mochila[encontrado].tipo);
    printf("Quantidade: %d\n", mochila[encontrado].quantidade);
}

// ------------------------ FUNÇÃO PRINCIPAL ------------------------

int main() {
    int opcao;

    while (1) {
        printf("\n=======================================\n");
        printf("        SISTEMA DE INVENTARIO\n");
        printf("=======================================\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem();
                listarItens();
                break;

            case 2:
                removerItem();
                listarItens();
                break;

            case 3:
                listarItens();
                break;

            case 4:
                buscarItem();
                break;

            case 5:
                printf("\nSaindo do sistema...\n");
                return 0;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}
