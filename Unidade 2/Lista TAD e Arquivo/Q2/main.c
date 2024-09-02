#include"produto.c"

int main() {
    const char *nomeArquivo = "estoque.bin";

    criarArquivoBinario(nomeArquivo);

    Produto produto1 = criarProduto(101, "Cadeira", 15);
    Produto produto2 = criarProduto(102, "Mesa", 8);
    Produto produto3 = criarProduto(103, "Sofa", 5);

    adicionarProdutoAoEstoque(nomeArquivo, produto1);
    adicionarProdutoAoEstoque(nomeArquivo, produto2);
    adicionarProdutoAoEstoque(nomeArquivo, produto3);

    exibirEstoque(nomeArquivo);

    atualizarQuantidadeDoProduto(nomeArquivo, 102, 12);

    exibirEstoque(nomeArquivo);

    removerProdutoDoEstoque(nomeArquivo, 103);

    exibirEstoque(nomeArquivo);

    return 0;
}