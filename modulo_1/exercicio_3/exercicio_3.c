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
 void main(void) {
	do{
		printf("Troco devido: ");
		if(scanf("%f",&value)!=1){
			while (getchar() != '\n'); //flushes the input buffer '-'
			}
	}while(value<=0);
	
	verifyCents(0.50f); //0.50 It tells the computer that this a floating point number, could be intepreted as an Integer or a Double
	verifyCents(0.25f);
	verifyCents(0.10f);
	verifyCents(0.05f);
	verifyCents(0.01f);
	
	if(value > 0){
		value = 0;
		coins ++;
		}
	printf("%d\n",coins);

 }
