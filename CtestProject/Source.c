
#define FF fflush(stdout);
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int a,b,aDigit, bDigit; long c;

	int i;
	printf("Input the Numbers to Multiply:");
	//scanf("%d %d", &a,&b);
	a = 50, b= 699;
	aDigit = log10((double)a)+1;
	bDigit = log10((double)b) +1;

	int *aArray = (int *)malloc(sizeof(int)*aDigit);
	int *bArray = (int *)malloc(sizeof(int)*bDigit);
	for (i = aDigit-1; i >=0; --i) {
		aArray[i] = a%10;
		a /= 10;
	}
	for (i = bDigit-1; i >=0; --i) {
			bArray[i] = b%10;
			b /= 10;
	}
return 0;


}
