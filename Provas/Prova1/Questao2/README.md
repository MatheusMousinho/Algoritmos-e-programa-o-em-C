Imagens em tons de cinza em computação podem ser representadas como matrizes de pixels, onde cada pixel apresenta uma tonalidade inteira entre preto (0) e branco (255). Uma das operações mais elementares é a binarização, que consiste em transformar todos os valores da imagem para preto (0) ou branco (255), sem valores intermediários, a depender de um valor limite (threshold). Todos os pixels maiores que este limite viram branco (255) e todos os menores viram preto (0). A figura abaixo mostra um exemplo de uma binarização:

Do lado direito, uma foto em tons de cinza com moedas dispersas sobre uma mesa de madeira; do lado esquerdo uma imagem somente em preto e branco com as moedas em cor branca.

Faça um programa que receba como entrada uma matriz quadrada m1 de tamanho NxN já preenchida de inteiros entre 0 e 255 (assuma que os valores estão neste intervalo) e gere uma nova matriz m2 também NxN que altera todos os valores de m1 maiores que um valor limite (threshold) para 255 e todos menores para 0. O valor limite (threshold) deve ser obtido calculando a média entre os valores de m1. Considere N = 3 para fins de teste, embora seu programa deva funcionar para qualquer valor inteiro de N. Informe o limite (threshold) e a matriz resultante ao usuário.

Implemente o programa requisitado em linguagem C. Indentação, organização e legibilidade, bem como a decisão do algoritmo e aplicação correta dos conteúdos vistos em aula fazem parte dos critérios de correção.

Exemplo:

m1:

10  50  40

120  65  15

170  14  16

Média de m1 (threshold) = 55.55

m2:

0  0  0

255  255  0

255  0  0

