Muitos códigos numéricos utilizam a ideia de um dígito verificador ao final do código como forma de garantir que o código está correto. O ISBN (International Standard Book Number) é um exemplo que consiste em uma coleção de 9 dígitos seguida de um décimo dígito de verificação.

Escreva um programa em C que leia os 9 primeiros dígitos de um ISBN e imprima o ISBN completo, incluindo o décimo dígito de verificação, que é calculado da seguinte maneira: multiplique o dígito mais à esquerda, considerado o primeiro dígito, por 10, o segundo por 9, e assim por diante, até o nono dígito, que deve ser multiplicado por 2. O somatório dessas multiplicações, somado ao dígito de verificação, deve resultar em um múltiplo inteiro de 11. O dígito de verificação é um valor inteiro entre 0 e 10 que é adicionado ao somatório para torná-lo um múltiplo de 11. No caso especial em que o valor seja 10, utilize o caractere 'X' para representar o dígito verificador; nos demais casos, utilize os algarismos de 0 a 9.

Dica: O dígito verificador a ser calculado é o valor que falta para que o resto da divisão do somatório por 11 seja igual a 11.

Exemplos do cálculo do dígito de verificação:

-> ISBN 853520926
Somatório: 8×10 + 5×9 + 3×8 + 5×7 + 2×6 + 0×5 + 9×4 + 2×3+ 6×2 = 250
Este valor 250 não é múltiplo de 11. Sobram 8 unidades do múltiplo anterior. Logo, faltam 3 unidades para alcançar o próximo múltiplo de 11, que é 253. Portanto o dígito de verificação seria 3.

-> ISBN 852521454
Somatório ponderado: 8×10 + 5×9 + 2×8 + 5×7 + 2×6 + 1×5 + 4×4 + 5×3+ 4×2 = 232
Este valor 232 não é múltiplo de 11. Sobra 1 unidade do múltiplo anterior. Logo, faltam 10 unidades para alcançar o próximo múltiplo de 11, que é 242. Portanto o dígito de verificação seria X (equivalente ao 10).


Exemplos de execução:
Entre com nove dígitos:
1
1
1
1
1
1
1
1
1
O ISBN é 111111111-1

Outro exemplo:
Entre com nove dígitos:
8
5
3
5
2
0
9
2
6
O ISBN é 853520926-3
