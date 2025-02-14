# Programação (Arquivos) - Olimpiadas
As Olimpíadas de Paris 2024 terminaram e você deve analisar quão bem a delegação brasileira foi nesta edição dos jogos.Para tal considere um arquivo "medalhas.txt" que possui o número de medalhas obtidas por uma lista de países, usando o seguinte formato. Note que os países no arquivo de entrada não precisam estar em ordem!

Formato do arquivo:

Exemplo “medalhas.txt” com 6 países:

NOME

OUROS PRATAS BRONZES

NOME

OUROS PRATAS BRONZES

NOME

OUROS PRATAS BRONZES

...

Estados Unidos
40 44 42
  
Romenia
3 4 2

Australia
18 19 16

Brasil
3 7 10

China
40 27 24

Canada
9 7 11

O programa deverá ler o arquivo com as medalhas (assuma que a lista terá no máximo 10 países) e salvar os dados em um vetor de estrutura PAIS, que conterá o nome do país, o numero de medalhas de ouro, de prata e de bronze, além de um quarto valor a ser computado indicando o somatório de medalhas daquele país. A leitura dos dados do arquivo deverá ser feita com o auxílio de uma função que receberá tal vetor como parâmetro.

Outra função deverá computar qual a posição no ranking de medalhas de um país com nome informado pelo usuário. O ranking considera o somatório de medalhas. (Para facilitar considere que não há empate). Se o nome não estiver na lista, o valor deve ser -1. Depois de calcular o ranking do país informado, mostre na tela a posição no ranking. Caso o nome informado não represente um país da lista, informe “Pais nao encontrado”. DICA: Você não precisa usar ordenação.

Enfim, crie um arquivo binário chamado totais.bin que contenha, para cada país, o nome do país (uma string com uma quantidade fixa de caracteres) e o total de medalhas do país.

Exemplos de execução:

Informe o nome do pais:

Brasil

Ranking: 5

Informe o nome do pais:

Wakanda

Pais nao encontrado

