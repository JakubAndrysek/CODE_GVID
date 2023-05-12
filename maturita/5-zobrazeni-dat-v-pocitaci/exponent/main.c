#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double exponentNaDesetine(int celeCislo, int exponent) {
	double result = celeCislo;
	if (celeCislo == 0 && exponent == 0) {
		printf("Error\n");
		return NAN;
	}


	for(int i = 0; i < abs(exponent); i++) {
		if(exponent > 0) {
			result *= 10;
		} else {
			result /= 10;
		}

	}
	return result;
}

double funkceNeniPotreba() {
	double result;
	sscanf("-4.25E-3", "%lf", &result);
	return result;
}

int main() {

	double des = exponentNaDesetine(124, -6); // 6 is maximum exponent (double stores 6 digits after decimal point)
	printf("Desetine: lf:%lf => g:%g\n", des, des);

	printf("%g\n", funkceNeniPotreba());
	return 0;
}