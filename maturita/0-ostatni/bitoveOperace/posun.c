#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




int main() {

	char* twoInteger = (char*)malloc(2 * sizeof(int));
	int saveToChar = 211;
	twoInteger[0] = (saveToChar >> 8) & 255;
	twoInteger[1] = saveToChar & 255;

	printf("twoInteger separated:\n");
	printf("%d\n", twoInteger[0]);
	printf("%d\n", twoInteger[1]);

	// print as hex
	printf("twoInteger separated as hex:\n");
	printf("%x\n", twoInteger[0]);
	printf("%x\n", twoInteger[1]);

	// print as binary
	printf("saveToCHar as binary:\n");
	for (int i = 0; i < 16; i++) {
		printf("%d", (saveToChar >> (15 - i)) & 1);
	}
	printf("\n");


	int loadFromChar = (twoInteger[0] << 8) | twoInteger[1];
	printf("%d\n", loadFromChar);

	free(twoInteger);


	return 0;
}