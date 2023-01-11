#include <stdio.h>

int main(){

	int layers = 1;
	printf("\nPlease enter the number of layers you want:");
	scanf("%d", &layers);
	printf("\n");
	for(int i =0; i < layers; i++){
		for(int k = 0; k < (layers - i); k++){
			printf(" ");
		}
		for(int o = 0; o < ((2*i) + 1); o++){
			printf("*");
		}
		for(int k = 0; k < (layers - i); k++){
					printf(" ");
		}
		printf("\n");
	}

	return 0;

}
