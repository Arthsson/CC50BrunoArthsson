#include <stdio.h> 
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int count_letters(const char *text) { //* indica que a variavel vai guardar um endereço e não um valor (ponteiro)
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) { // \0 é colocado na string(char) para identificar o fim da string(char) 
        if (isalpha(text[i])) {
            count++;
        }
    }
    return count;
}

int count_words(const char *text) {
    int count = 1; 
    for (int i = 0; text[i] != '\0'; i++) {
        if (isblank(text[i])) {
            count++;
        }
    }
    return count;
}

int count_sentences(const char *text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            count++;
        }
    }
    return count;
}

int calculate_index(int letters, int words, int sentences) {
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    return (int)round(0.0588 * L - 0.296 * S - 15.8);
}

int main(void) {
    char text[1000];
	
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    int index = calculate_index(letters, words, sentences);

    if (index >= 16) {
        printf("Grade 16+\n");
    } else if (index < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade %d\n", index);
    }

    return 0;
}
