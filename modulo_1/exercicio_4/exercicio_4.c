#include <stdio.h>
#include <stdlib.h> // alocação de memória, controle de processos, conversão ...
#include <string.h> // manipular string '-'
#include <ctype.h> // manipular caracteres '-'

void main(void) {
    char input[100];
    long numberCard;
    int length = 0;
    int unit, ten;
    int soma = 0;
    char cardType[20];

    printf("Digite o numero do cartao: ");
    while (fgets(input, sizeof(input), stdin) != NULL) { //ler a entrada stdin ate o tamanho sizeof() do input [100]
        int isValidInput = 1;
        length = strlen(input) - 1;

        for (int i = 0; i < length; i++) {
            if (!isdigit(input[i])) { //verificar se não contem letras ou caracteres especiais
                isValidInput = 0;
                break;
            }
        }

        if (isValidInput) {
            break; 
        } else {
            printf("Entrada invalida. Digite apenas numeros: ");
        }
    }

    numberCard = strtol(input, NULL, 10); // convertendo em long (variavel em string, referencia do char(ponteiro), base numérica) 

    for (int i = length - 2; i >= 0; i -= 2) {
        int digit = (input[i] - '0') * 2;
        if (digit >= 10) {
            ten = digit / 10;
            unit = digit % 10;
            soma += (ten + unit);
        } else {
            soma += digit;
        }
    }

    for (int i = length - 1; i >= 0; i -= 2) {
        int digit = (input[i] - '0');
        soma += digit;
    }

    if (soma % 10 == 0) {
        if ((length == 15 && (input[0] == '3' && (input[1] == '4' || input[1] == '7')))) {
            strcpy(cardType, "/AMERICAN"); //copiar conteudo de uma string para outra ( cardtype = "/AMERICAN" )
        } else if ((length == 16 && input[0] == '5' && (input[1] >= '1' && input[1] <= '5'))) {
            strcpy(cardType, "/MASTER");
        } else if ((length == 13 || length == 16) && input[0] == '4') {
            strcpy(cardType, "/VISA");
        } else {
			printf("nao possui bandeira");
            strcpy(cardType, "/INVALID");
        }
    } else {
		printf("soma%10 != 0");
        strcpy(cardType, "/INVALID");
    }

    printf("Status: %s\n", cardType);
}
