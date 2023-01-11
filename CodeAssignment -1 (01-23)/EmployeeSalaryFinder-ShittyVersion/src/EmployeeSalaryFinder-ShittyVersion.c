#include <stdio.h>

int main(){

	char EMP1[100], EMP2[100], EMP3[100], EMP4[100], EMP5[100];
	long unsigned int SEMP1, SEMP2, SEMP3, SEMP4, SEMP5;
	int index_no = 1;

	printf("\nEnter employee 1:\n");
	fgets(EMP1, sizeof(EMP1), stdin);
	printf("\nEnter %s's salary:\n", EMP1);
	scanf("%lud", &SEMP1);

	printf("\nEnter employee 2:\n");
	fgets(EMP2, sizeof(EMP2), stdin);
	printf("\nEnter %s's salary:\n", EMP2);
	scanf("%lud", &SEMP2);

	printf("\nEnter employee 3:\n");
	fgets(EMP3, sizeof(EMP3), stdin);
	printf("\nEnter %s's salary:\n", EMP3);
	scanf("%lud", &SEMP3);

	printf("\nEnter employee 4:\n");
	fgets(EMP4, sizeof(EMP4), stdin);
	printf("\nEnter %s's salary:\n", EMP4);
	scanf("%lud", &SEMP4);

	printf("\nEnter employee 5:\n");
	fgets(EMP5, sizeof(EMP5), stdin);
	printf("\nEnter %s's salary:\n", EMP5);
	scanf("%lud", &SEMP5);

	printf("\nThe employee(s) with salaries above 10,000 are:\n");

	if(SEMP1 >= 10000){
		printf("%d.%s : %lud", index_no, EMP1, SEMP1);
		index_no++;

	}
	if(SEMP2 >= 10000){
			printf("%d.%s : %lud", index_no, EMP2, SEMP2);
			index_no++;
	}
	if(SEMP3 >= 10000){
			printf("%d.%s : %lud", index_no, EMP3, SEMP3);
			index_no++;
	}
	if(SEMP4 >= 10000){
			printf("%d.%s : %lud", index_no, EMP4, SEMP4);
			index_no++;
	}
	if(SEMP5 >= 10000){
			printf("%d.%s : %lud", index_no, EMP5, SEMP5);
			index_no++;
	}

	return 0;

}
