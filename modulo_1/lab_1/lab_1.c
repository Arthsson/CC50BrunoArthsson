# include<stdio.h>

int main(void){
	int initNumberLhama, endNumberLhama, year = 0;
 	 // TODO: Solicite o valor inicial ao usuário
		do{
			printf("Digite o numero inicial de lhamas: ");
	    	scanf("%d", &initNumberLhama);
		}while(initNumberLhama<9);
		
     // TODO: Solicite o valor final ao usuário
		do{
			printf("Digite o numero final de lhamas: ");
	    	scanf("%d", &endNumberLhama);
		}while(endNumberLhama<=initNumberLhama);

     // TODO: Calcule o número de anos até o limite
		while(endNumberLhama>initNumberLhama){
			initNumberLhama += (initNumberLhama/3) - (initNumberLhama/4);
			year++;
		}
     // TODO: Imprima o número de anos
		printf("Quantidade de anos: %d\n",year);
}
