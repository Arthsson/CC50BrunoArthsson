#include <stdio.h>
#include <math.h>

 int coins = 0;
 float value;

 void verifyCents(float coinValue){
	while(value >= coinValue){
		value -= coinValue;
		coins ++;
		}
	}
 int main(void) {
	do{
		printf("Troco devido: ");
		if(scanf("%f",&value)!=1){
			while (getchar() != '\n');
			}
	}while(value<=0);
	
	verifyCents(0.50f);
	verifyCents(0.25f);
	verifyCents(0.10f);
	verifyCents(0.05f);
	verifyCents(0.01f);
	
	if(value > 0){
		value = 0;
		coins ++;
		}
	printf("%d\n",coins);

   return 0;
 }
