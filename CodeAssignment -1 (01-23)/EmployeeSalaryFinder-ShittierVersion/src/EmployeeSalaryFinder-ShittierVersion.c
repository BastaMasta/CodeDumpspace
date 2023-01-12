#include <stdio.h>

int main(){

	char EMP1, EMP2, EMP3, EMP4, EMP5;
	long unsigned int SEMP1, SEMP2, SEMP3, SEMP4, SEMP5;
	int index_no = 1;

	printf("\nEnter employee 1 (Single Character):\n");
	scanf("%c", &EMP1);
	printf("\nEnter %c's salary:\n", EMP1);
	scanf("%lud", &SEMP1);

	printf("\nEnter employee 2 (Single Character):\n");
	scanf("%c", &EMP2);
	printf("\nEnter %c's salary:\n", EMP2);
	scanf("%lud", &SEMP2);

	printf("\nEnter employee 3 (Single Character):\n");
	scanf("%c", &EMP3);
	printf("\nEnter %c's salary:\n", EMP3);
	scanf("%lud", &SEMP3);

	printf("\nEnter employee 4 (Single Character):\n");
	scanf("%c", &EMP4);
	printf("\nEnter %c's salary:\n", EMP4);
	scanf("%lud", &SEMP4);

	printf("\nEnter employee 5 (Single Character):\n");
	scanf("%c", &EMP5);
	printf("\nEnter %c's salary:\n", EMP5);
	scanf("%lud", &SEMP5);

	printf("\nThe employee(s) with salaries above 10,000 are:\n");

	if(SEMP1 >= 10000){
		printf("%d.%c : %lud", index_no, EMP1, SEMP1);
		index_no++;

	}
	if(SEMP2 >= 10000){
			printf("%d.%c : %lud", index_no, EMP2, SEMP2);
			index_no++;
	}
	if(SEMP3 >= 10000){
			printf("%d.%c : %lud", index_no, EMP3, SEMP3);
			index_no++;
	}
	if(SEMP4 >= 10000){
			printf("%d.%c : %lud", index_no, EMP4, SEMP4);
			index_no++;
	}
	if(SEMP5 >= 10000){
			printf("%d.%c : %lud", index_no, EMP5, SEMP5);
			index_no++;
	}

	return 0;

}
