#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int readNumbers(FILE* f, int num[]) {

	int count = 0;
	while(fscanf(f, "A:%d ", &num[count]) == 1) {
		printf("%d, ", num[count]);
		count++;
	}
	printf("\n");
	return count;
}


int main() {

	FILE* f = fopen("numbers.txt", "r");

	if(f == NULL) {
		printf("Error opening numbers\n");
		return 1;
	}

	int num[100];

	int countNum = readNumbers(f, num);
	printf("Number count: %d\n", countNum);

	return 0;
}