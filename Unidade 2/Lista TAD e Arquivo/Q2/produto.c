#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"produto.h"

struct produto{
    int codigo;
    char descricao[100];
    int quantidade;
};

Produto criarProduto(int codigo, const char *descricao, int quantidade) {
    Produto produto;
    produto.codigo = codigo;
    strncpy(produto.descricao, descricao, sizeof(produto.descricao) - 1);
    produto.descricao[sizeof(produto.descricao) - 1] = '\0'; // Garante que a string é terminada em '\0'
    produto.quantidade = quantidade;
    return produto;
}

void adicionarProdutoAoEstoque(const char *nomeArquivo, Produto produto) {
    FILE *arquivo = fopen(nomeArquivo, "ab"); // Abre o arquivo em modo de adição binária
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }
    fwrite(&produto, sizeof(Produto), 1, arquivo);
    fclose(arquivo);
}

void removerProdutoDoEstoque(const char *nomeArquivo, int codigo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    FILE *arquivoTemp = fopen("temp.bin", "wb");
    if (arquivoTemp == NULL) {
        printf("Erro ao criar arquivo temporario!\n");
        fclose(arquivo);
        return;
    }

    Produto produto;
    int encontrado = 0;

    while (fread(&produto, sizeof(Produto), 1, arquivo)) {
        if (produto.codigo != codigo) {
            fwrite(&produto, sizeof(Produto), 1, arquivoTemp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(arquivoTemp);

    if (encontrado) {
        remove(nomeArquivo);
        rename("temp.bin", nomeArquivo);
        printf("Produto com codigo %d removido com sucesso!\n", codigo);
    } else {
        printf("Produto com codigo %d não encontrado.\n", codigo);
        remove("temp.bin");
    }
}

void atualizarQuantidadeDoProduto(const char *nomeArquivo, int codigo, int novaQuantidade) {
    FILE *arquivo = fopen(nomeArquivo, "rb+"); // Abre o arquivo em modo de leitura e escrita binária
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura e escrita!\n");
        return;
    }

    Produto produto;
    int encontrado = 0;

    while (fread(&produto, sizeof(Produto), 1, arquivo)) {
        if (produto.codigo == codigo) {
            produto.quantidade = novaQuantidade;
            fseek(arquivo, -sizeof(Produto), SEEK_CUR); // Volta o ponteiro para sobrescrever
            fwrite(&produto, sizeof(Produto), 1, arquivo);
            encontrado = 1;
            printf("Quantidade do produto com codigo %d atualizada para %d.\n", codigo, novaQuantidade);
            break;
        }
    }

    if (!encontrado) {
        printf("Produto com codigo %d não encontrado.\n", codigo);
    }

    fclose(arquivo);
}

void exibirEstoque(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb"); // Abre o arquivo em modo de leitura binária
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    Produto produto;
    printf("Codigo\tDescricao\t\tQuantidade\n");
    printf("-------------------------------------------\n");
    while (fread(&produto, sizeof(Produto), 1, arquivo)) {
        printf("%d\t%-20s\t%d\n", produto.codigo, produto.descricao, produto.quantidade);
    }

    fclose(arquivo);
}

void criarArquivoBinario(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb"); // Cria um arquivo binário vazio
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }
    fclose(arquivo);
    printf("Arquivo '%s' criado com sucesso!\n", nomeArquivo);
}