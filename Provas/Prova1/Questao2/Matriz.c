#include <stdio.h>
#define TAMANHO 9
#define MULTIPLO 11

int main(){
	//Variáveis
	int somatorio = 0;
	int valorMultiplicação = 0;
	int ultimoDigito = 0;
	int isbn[TAMANHO];
	char ultimoDigito10 = 'X';
	
	//Recebendo os dígitos do código
	printf("Entre com os nove dígitos: \n");
	for(i = 0; i < 9; i++){
		scanf("%d", &isbn[i]);
		
	}
	
	//Calculando o somatório
	for(i = 0; i < 9; i++){
		valorMultiplicação = (isnb[i] * (10 - i));
		somatorio += valorMultiplicação;
			
	}
	
	//Calculando último dígito
	ultimoDigito = (MULTIPLO - (somatorio % MULTIPLO));
	
	//Imprimindo a resposta
	if(ultimoDigito == 10){
		printf("O ISBN é %d-%c", isbn, ultimoDigito10); 
	}else{
		printf("O ISBN é %d-%d", isbn, ultimoDigito);
	}
	


	return 0
}
