#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


float horner(float array[], int size, int coef) {
	float sum = 0;

	for(int i = 0; i < size; i++) {
		sum = sum * coef + array[i];
	}
	return sum;
}


void testHorner() {
	float array[] = {1, 2, 3, 4, 5};
	int size = sizeof(array) / sizeof(array[0]);
	int coef = 2;

	printf("Horner: %g\n", horner(array, size, coef));
}

void histogramAbecedy

void testHistogramAbecedy() {
	char abeceda[26];




int main() {

	testHorner();



	return 0;
}