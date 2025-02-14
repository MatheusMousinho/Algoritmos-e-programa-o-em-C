#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAISES 10
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int ouros;
    int pratas;
    int bronzes;
    int total;
} PAIS;

// Função para ler o arquivo de texto e preencher o vetor de estruturas
void ler_arquivo(const char *nome_arquivo, PAIS paises[], int *num_paises) {
    //ler arquivo
	FILE *arquivo = fopen(nome_arquivo, "r");
	
	//caso arquivo não abra
    if (!arquivo) { 
        perror("Erro");
        exit(EXIT_FAILURE);
    }
    
	//Se o arquivo abrir, coletar as informações
    while (fgets(paises[*num_paises].nome, MAX_NOME, arquivo) != NULL) {
		
		// pegando nome do país
        paises[*num_paises].nome[strcspn(paises[*num_paises].nome, "\n")] = '\0'; 
		
		//pegando as medalhas do país
        fscanf(arquivo, "%d %d %d", &paises[*num_paises].ouros, &paises[*num_paises].pratas, &paises[*num_paises].bronzes); 
		
		//calculando total de medalhas do país
        paises[*num_paises].total = paises[*num_paises].ouros + paises[*num_paises].pratas + paises[*num_paises].bronzes; 
		
        //incrementando no número de países
		(*num_paises)++; 
        fgetc(arquivo); 
    }

    fclose(arquivo);
}

// Função para calcular o ranking de um país
int calcular_ranking(const PAIS paises[], int num_paises, const char *nome_pais) {
    int total_pais = 0;
	//verificando se o pais está no arquivo
    for (int i = 0; i < num_paises; i++) {
		//Se estiver, guardando a quantidade de países que vem antes dele
        if (paises[i].nome == nome_pais){
            total_pais = paises[i].total;
            break;
        }
    }
	//Se o país não estiver no arquivo
    if (total_pais == 0) return 0;

	//Se estiver no arquivo
    int posicao = 1;
	//Pegando o Ranking do arquivo
    for (int i = 0; i < num_paises; i++) {
        if (paises[i].total > total_pais) {
            posicao++;
        }
    }
    return posicao;
}

// Função para criar o arquivo binário
void criar_arquivo_binario(const char *nome_arquivo_binario, const PAIS paises[], int num_paises) {
    FILE *arquivo_binario = fopen(nome_arquivo_binario, "wb");
	//Caso não consiga criar o arquivo
    if (!arquivo_binario) {
        perror("Erro");
        exit(EXIT_FAILURE);
    }

	//Caso consiga abrir o arquivo 
    for (int i = 0; i < num_paises; i++) {
		
		//escrevendo no arquivo
        fwrite(paises[i].nome, sizeof(char), MAX_NOME, arquivo_binario);
        fwrite(&paises[i].total, sizeof(int), 1, arquivo_binario);
    }

    fclose(arquivo_binario);
}

int main() {
    PAIS paises[MAX_PAISES];
    int num_paises = 0;
    char nome_pais[MAX_NOME];

	//Lendo arquivo
    ler_arquivo("medalhas.txt", paises, &num_paises);

	//Lendo o país escolhido pelo usuário
    printf("Informe o nome do pais:\n")
    scanf("%s", noome_pais);

	//pegando a posição pela função que calcula o ranking
    int posicao = calcular_ranking(paises, num_paises, nome_pais);
    if (posicao == 0) {
        printf("Pais nao encontrado");
    } else {
        printf("Ranking: %d\n", posicao);
    }
	
	//criando o arquivo binario
    criar_arquivo_binario("totais.bin", paises, num_paises);

    return 0;
}
