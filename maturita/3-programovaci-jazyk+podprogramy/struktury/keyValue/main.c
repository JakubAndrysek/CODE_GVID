#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	char key;
	int value;
} KeyValue;


KeyValue readPair(FILE* file) {
	KeyValue result;
	if(!fscanf(file, ">%c:%d\n", &result.key, &result.value) == 1) {
		printf("Error reading");
		return result;
	}
	return result;
}

int readPairs(FILE* f, KeyValue keyValues[]) {

	int count = 0;
	while(fscanf(f, ">%c:%d\n", &keyValues[count].key, &keyValues[count].value) == 2) {
		printf(" --> Nacteno: %c:%d\n", keyValues[count].key, keyValues[count].value);
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

	KeyValue keyValue = readPair(f);
	printf("%c: %d\n", keyValue.key, keyValue.value);

	const int count = 10;
	KeyValue keyValues[count];

	readPairs(f, keyValues);

	for(int i = 0; i < count; i++) {
		if(keyValues[i].key > 'A' && keyValues[i].key < 'Z') {
			printf("%c: %d\n", keyValues[i].key, keyValues[i].value);
		}
	}

	return 0;
}