// Definição da TAD Produto
typedef struct produto Produto;

// Função para criar um novo produto
Produto criarProduto(int codigo, const char *descricao, int quantidade);

// Função para adicionar um produto ao estoque
void adicionarProdutoAoEstoque(const char *nomeArquivo, Produto produto);

// Função para remover um produto do estoque com base no código
void removerProdutoDoEstoque(const char *nomeArquivo, int codigo);

// Função para atualizar a quantidade de um produto em estoque
void atualizarQuantidadeDoProduto(const char *nomeArquivo, int codigo, int novaQuantidade);

// Função para exibir todos os produtos no estoque
void exibirEstoque(const char *nomeArquivo);

// Função para criar um arquivo binário vazio (caso não exista)
void criarArquivoBinario(const char *nomeArquivo);