#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void saxpy_c(int n, float A, float X[], float Y[], float Z[]) {

	for (int i = 0; i < n; i++) {

		Z[i] = (A * X[i]) + Y[i];

	}
	
	return;
}