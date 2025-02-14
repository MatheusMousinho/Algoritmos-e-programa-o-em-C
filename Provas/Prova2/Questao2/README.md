# Gerenciamento de Estoques de Produtos
Escreva um programa em C que implemente um sistema básico de gerenciamento de estoque de produtos. O programa deve permitir ao usuário selecionar as seguintes opções: cadastrar produto, exibir todos os produtos em estoque e permitir alterar o estoque de um determinado produto através de seu índice. As informações de cada produto devem ser armazenadas em uma estrutura (struct) conforme definido abaixo. O sistema deve funcionar para até 100 produtos.

typedef struct {
  char nome[100]; // Nome do produto
  float preco; // Preço do produto
  int quantidade; // Quantidade do produto em estoque
} Produto;

A sua solução deve contemplar a função principal (main), com toda a lógica de
gerenciamento de estoque de produtos (cadastro, exibição e alteração de estoque de produtos). As opções do gerenciamento devem ser implementadas por funções obrigatoriamente com os seguintes protótipos:

Produto cadastrarProduto(); // Cadastrar um novo produto, cujas informações são entradas pelo usuário via teclado dentro da própria função

void exibirEstoque(Produto produtos[], int total_produtos); // Mostrar todos os produtos disponíveis no vetor de produtos

void alterarQuantidade(Produto *produto); // Alterar a quantidade de elementos de um único produto, cuja nova quantidade é fornecida pelo usuário via teclado na própria função
