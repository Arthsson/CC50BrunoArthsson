#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { // recebe a key antes da execução do programa na chamada da função principal, pode ser feito a patir do prompt - ceasar.exe 10
  
    if (argc != 2) { //verifica a quantidade de argumentps
        printf("Usage: %s key\n", argv[0]); //argv[0] retorna o path
        return 1;
    }

    
    char *key = argv[1];
    for (int i = 0; i < strlen(key); i++) {
        if (!isdigit(key[i])) {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }

    
    int k = atoi(key); //passando para inteiro

    char plaintext[1000];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            printf("%c \n", (plaintext[i] - base + k) % 26 + base);
        } else {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");

    return 0;
}

