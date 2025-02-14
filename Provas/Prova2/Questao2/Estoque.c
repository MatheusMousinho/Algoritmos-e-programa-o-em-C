#include <stdio.h>
#define MAX 100

typedef struct produto{
  char nome[MAX]; // Nome do produto
  float preco; // Preço do produto
  int quantidade; // Quantidade do produto em estoque
} Produto;

//Variáveis globais
int total_produtos = 0;
Produto vetorProdutos[MAX];

//Função que cadastra um novo produto
Produto cadastrarProduto(){
	
	//pegando nome do produto
	printf("Digite o nome do produto: ")
	char nome[MAX] = scanf("%s", nome);
	
	//pegando preço do produto
	printf("\n Digite o preço do produto: ")
	float preco = scanf("%f", preco);
	
	//pegando quantidade do produto
	printf("\n Digite a quantidade do produto: ")
	int qtdd[MAX] = scanf("%d", qtdd);
	
	Produto retornoProduto = { nome, preco, qtdd };
	
	return retornoProduto;
}

//Função que exibe o estoque
void exibirEstoque(Produto vetorProdutos[], int total_produtos){
	for( int i = 0; i < total_produtos; i++){
		//Escrevendo cada produto disponível no estoque
		printf("Produto: %s está disponivel", vetorProdutos[i].nome); 
	}
}

//Função que altera quantidade de um certo produto escolhido pelo usuário
void alterarQuantidade(Produto produto){
	int alterarProduto = 0;
	//pegando qual a quantidade do produto escolhido
	printf("Qual a nova quantidade do produto?");
	scanf("%d", &alterarProduto);
	
	//alterando quantidade do produto escolhido
	produto.quantidade == alterarProduto;
	
}

int main(){
	int escolha = 0;
	int aux = 0;
	
	//enquanto o usuario não escolher a opção 4, continuara rodando
	do {
		printf("Digite o número para a instrução desejada \n 1: Cadastrar produto \n  2: Exibit estoque \n 3: Alterar quantidade \n 4: Fechar o programa");
		scanf("%c", &escolha);
		
		//caso o usuario escolha 1
		if(escolha == 1){
			if(total_produtos < MAX){
				vetorProduto[total_produtos] = cadastrarProduto();
				total_produtos += 1
			}else{
				printf("O estoque está cheio")
			}				
		}
		
		//caso o usuario escolha 2
		if(escolha == 2){
			exibirEstoque(vetorProdutos, total_produtos)
			
		}
		
		//caso o usuario escolha 3
		if(escolha == 3){
			//pegando qual produto será alterado 
			printf("Qual produto deseja alterar a quantidade em estoque?")
			scanf("%s", aux);
			
			//verificando se existe este produto
			for(int i = 0; i < total_produtos; i++){
				if( aux == vetorProduto[i].nome ){
					alterarQuantidade(vetorProduto[i])
					
				}
				
			}
			
			
		}
		///caso o usuario escolha 4 - Finaliza o loop
	} while (escolha != 4)
	
	
	return 0;
}
