#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int PREFIX_LEN = (int)(sizeof(int) + sizeof(int));

// look back 2 bytes before the string
int stringSizeGet(char *string) {
	return *((int*)string - 2);
}

void stringSizeSet(char *string, int size) {
	*((int*)string - 2) = size;
}

// look back 1 byte before the string
int stringCapacityGet(char *string) {
	return *((int*)string - 1);
}

void stringCapacitySet(char *string, int capacity) {
	*((int*)string - 1) = capacity;
}

// returned string is a pointer to the first character of the string
char* stringCreate() {
	int size = 1; // including the null terminator
	int capacity = 4;
	char *string = (char*)malloc(sizeof(char)*capacity + PREFIX_LEN);
	if(string != NULL) {
		// shift the pointer to the first character of the string
		string += sizeof(int) + sizeof(int);
		string[0] = '\0';

		// store size and capacity in the first 2 bytes
		stringSizeSet(string, size);
		stringCapacitySet(string, capacity);
	}
	return string;
}


void stringDestroy(char *string) {
	char* stringStart2 = string - PREFIX_LEN;
	free(stringStart2);
}



// pointer is pointing to the first character of the string
void stringPrintVerbose(char *string) {
	int size = stringSizeGet(string);
	int capacity = stringCapacityGet(string);
	printf("size: %d, capacity: %d, string: >%s<\n", size, capacity, string);
}

// pointer is pointing to the first character of the string
void stringPrint(char *string) {
	printf("%s", string);
}

void stringPrintln(char *string) {
	stringPrint(string);
	printf("\n");
}

// pointer is pointing to the first character of the string
// save char c to the end of the string but before the null terminator
void stringAdd(char *string, char c) {
	int size = stringSizeGet(string);
	int capacity = stringCapacityGet(string);



	if(size >= capacity) {
		capacity *= 2;
		char* newstring = (char*)realloc(string - PREFIX_LEN, sizeof(char) * capacity + PREFIX_LEN);
		if(newstring != NULL) {
			string = newstring + PREFIX_LEN;
			stringCapacitySet(string, capacity);
		} else {
			printf("ERROR: stringAdd failed\n");
			return;
		}
	}

	string[size] = string[size - 1]; // move the null terminator
	string[size - 1] = c; // add the character
	stringSizeSet(string, size + 1);

	stringPrintVerbose(string);
	printf("");
}



int main() {
	char *string = stringCreate();
	stringPrintVerbose(string);
	stringAdd(string, 'a');
	stringAdd(string, 'b');
	stringAdd(string, 'c');
	stringAdd(string, 'd');
	stringAdd(string, 'e');
	stringPrintVerbose(string);

	// stringPrint(string);
	stringDestroy(string);
	return 0;
}