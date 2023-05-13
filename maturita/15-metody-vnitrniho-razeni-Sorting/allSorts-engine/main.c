#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*eventTestSort)(int arr[], int arrLen);

bool isSorted(int arr[], int len) {
	for(int i=1; i<len; i++) {
		if(arr[i-1] > arr[i]) {
			return false;
		}
	}
	return true;
}

void genTestArray(int arr[], int len, int max) {
	for(int i=0; i<len; i++) {
		arr[i] = rand() % max - rand() % max;
	}
}

void printArray(int arr[], int len) {
	for(int i=0; i<len; i++) {
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

void printStatus(int arr[], int len) {
	printf(" -> SORTED: %s\n", isSorted(arr, len) ? "OK" : "NOT");
}

void swipe(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

bool testBench(char *name, eventTestSort sortFunction) {
	int arrShort[] = {9, 5,1, 4, 3, 4};
	int arrShortLen = sizeof(arrShort)/sizeof(arrShort[0]);

	int arrLong[50];
	int arrLongLen = sizeof(arrLong)/sizeof(arrLong[0]);

	printf("Testing: %s\n", name);
	printArray(arrShort, arrShortLen);
	sortFunction(arrShort, arrShortLen);
	if(!isSorted(arrShort, arrShortLen)) {
		printArray(arrShort, arrShortLen);
		printf("ERROR: Basic test\n\n");
		return false;
	}
	printArray(arrShort, arrShortLen);
	printStatus(arrShort, arrShortLen);

	for(int id = 0; id < 1000; id++) {
		genTestArray(arrLong, arrLongLen, 99);
		sortFunction(arrLong, arrLongLen);
		if(!isSorted(arrLong, arrLongLen)) {
			printf("ERROR: Long test[%d]: ", id);
			printArray(arrLong, arrLongLen);
			return false;
		}
	}
	printf("All tests passed -> OK\n\n");
	return true;
}


// https://www.programiz.com/dsa/selection-sort
void selectionSort(int arr[], int arrLen) {
	for(int out=0; out<arrLen-1; out++) { // vnejsi kontrola od zacatku po konec -1 (vzdy bude jeden nejvetsi)
		int min_index = out; // nastavim index na prvni mozny v zavislosti na OUT (ty pred nim uz jsou serazene)
		for(int in=out+1; in<arrLen; in++) { // porovnavam se vsemi po OUT
			if(arr[in] < arr[min_index]) {
				min_index = in; // pokud je prvek mensi, nastavim ho jako min_index
			}
		}
		swipe(&arr[out], &arr[min_index]); // po najiti nejmensiho je prehodim
	}
}

// https://www.programiz.com/dsa/insertion-sort
void insertionSort(int arr[], int arrLen) {
	for(int step=1; step < arrLen; step++) { // od 1 (ne 0) po posledni (prvni nemam kam posunovat)
		int key = arr[step]; // ulozim si kopii porovnavaneho prvku
		int j = step - 1; // porovnavam s o i Mensim
		while(key < arr[j] && j >=0) { // posouvam prvky odzadu v serazene oblasti, dokud nenajdu pozadovane misto NEBO nenarazim na uplny zacatek pole (zde probihaji vylepsini - zarazka)
			arr[j+1] = arr[j]; // posouvani
			j--;
		}
		arr[j+1] = key; // musi tam byt j+1, protoze jsem po poslednim wile Odecetl -1
	}
}

// https://www.programiz.com/dsa/bubble-sort
void bubbleSort(int arr[], int arrLen) {
	for(int out=0; out<arrLen-1; out++) { // prochazim od zacatku po konec (v kazdem kroku vybubla jeden prvek od konce)
		for(int in = arrLen-2; in>=out; in--) { // od konce porovnavam prvky
			if(arr[in] > arr[in+1]) { // mensi prehodim dopredu mezi sebou
				swipe(&arr[in], &arr[in+1]);
			}
		}
	}
}



int main() {
	srand(time(NULL));

	testBench("Selection sort", selectionSort);

	testBench("Insertion sort", insertionSort);

	testBench("Bubble sort", bubbleSort);

  	return 0;
}