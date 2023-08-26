#include <stdio.h>

int main() {
    int height; 
	
	do{
		printf("Tamanho: ");
		if (scanf("%d", &height) != 1) {
			while (getchar() != '\n');
		}
	}
	while(height<=0 || height>8);

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height - i; j++) {
            printf(" ");
        } 
        for (int k = 1; k <= i; k++) {
            printf("#");
        }
		printf(" ");
		for (int k = 1; k <= i; k++) {
            printf("#");
        }
        printf("\n");
    }
   return 0;
}

