#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

#define resultcount 10 // Limit results to first 10 elements
#define testcount 30	// Run tests 30 times
#define maxfloat 100.0	// Randomly generated floats range from 0.000000 to 100.000000
#define twopow20 1048576
#define twopow24 16777216
#define twopow27 134217728	// Highest possible size for an array in stack
static float X_testvec[twopow27]; 
static float Y_testvec[twopow27];
static float Z_resultvec[twopow27]; 

extern void saxpy_asm(int n, float A, float X[], float Y[], float Z[]);
// Has to be the same name as in .ASM file (extern)

extern void saxpy_c(int n, float A, float X[], float Y[], float Z[]);
// n = size of the vectors ; A = scalar value ; X[] = first vector ; Y[] = second vector ; Z[] = resulting vector
// Z[i] = A * X[i] + Y[i]

void call_c_kernel(int n, float A, float X[], float Y[], float Z[]);
void call_asm_kernel(int n, float A, float X[], float Y[], float Z[]);

int main() {
	srand((unsigned int)time(NULL));
	int vecsize;
	float A_testscalar;
	
	// Test A : 2^20 sized vectors with randomly generated floats
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||| Testing Using Randomly Generated 2^20 Sized Vectors |||\n");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
		// Initializing test variables
		vecsize = twopow20;	// Initialize value of vector
		A_testscalar = (((float)rand() / (float)(RAND_MAX)) * maxfloat); // Generate random scalar (A)
		for (int i = 0; i < vecsize; i++) X_testvec[i] = (((float)rand() / (float)(RAND_MAX)) * maxfloat);	// Generate random values for Vector X
		for (int i = 0; i < vecsize; i++) Y_testvec[i] = (((float)rand() / (float)(RAND_MAX)) * maxfloat);  // Generate random values for Vector Y
		printf("\nExecute SAXPY Function: Z[i] = A*X[i]+Y[i]\n");
		printf("\nScalar Value A: %.3f", A_testscalar);
		printf("\nVector X (1st 10):\t\t Vector Y (1st 10):\n");
		for (int i = 0; i < 10; i++) {
			printf("%.3f\t\t\t\t %.3f\n", X_testvec[i], Y_testvec[i]);
		}
		printf("...\t\t\t\t ...\n");
		

		//////// C KERNEL ////////
		call_c_kernel(vecsize, A_testscalar, X_testvec, Y_testvec, Z_resultvec);
		
		//////// ASM KERNEL ////////
		call_asm_kernel(vecsize, A_testscalar, X_testvec, Y_testvec, Z_resultvec);

	// Test B : 2^24 sized vectors with randomly generated floats
	printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||| Testing Using Randomly Generated 2^24 Sized Vectors |||\n");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
		// Initializing test variables
		vecsize = twopow24;	// Initialize value of vector
		A_testscalar = (((float)rand() / (float)(RAND_MAX)) * maxfloat); // Generate random scalar (A)
		for (int i = 0; i < vecsize; i++) X_testvec[i] = (((float)rand() / (float)(RAND_MAX)) * maxfloat);	// Generate random values for Vector X
		for (int i = 0; i < vecsize; i++) Y_testvec[i] = (((float)rand() / (float)(RAND_MAX)) * maxfloat);  // Generate random values for Vector Y
		printf("\nExecute SAXPY Function: Z[i] = A*X[i]+Y[i]\n");
		printf("\nScalar Value A: %.3f", A_testscalar);
		printf("\nVector X (1st 10):\t\t Vector Y (1st 10):\n");
		for (int i = 0; i < 10; i++) {
			printf("%.3f\t\t\t\t %.3f\n", X_testvec[i], Y_testvec[i]);
		}
		printf("...\t\t\t\t ...\n");

		//////// C KERNEL ////////
		call_c_kernel(vecsize, A_testscalar, X_testvec, Y_testvec, Z_resultvec);

		//////// ASM KERNEL ////////
		call_asm_kernel(vecsize, A_testscalar, X_testvec, Y_testvec, Z_resultvec);




	// Test C : 2^27 sized vectors with randomly generated floats
	printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("||| Testing Using Randomly Generated 2^27 Sized Vectors |||\n");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
		// Initializing test variables
		vecsize = twopow27;	// Initialize value of vector
		A_testscalar = (((float)rand() / (float)(RAND_MAX)) * maxfloat); // Generate random scalar (A)
		for (int i = 0; i < vecsize; i++) X_testvec[i] = (((float)rand() / (float)(RAND_MAX)) * maxfloat);	// Generate random values for Vector X
		for (int i = 0; i < vecsize; i++) Y_testvec[i] = (((float)rand() / (float)(RAND_MAX)) * maxfloat);  // Generate random values for Vector Y
		printf("\nExecute SAXPY Function: Z[i] = A*X[i]+Y[i]\n");
		printf("\nScalar Value A: %.3f", A_testscalar);
		printf("\nVector X (1st 10):\t\t Vector Y (1st 10):\n");
		for (int i = 0; i < 10; i++) {
			printf("%.3f\t\t\t\t %.3f\n", X_testvec[i], Y_testvec[i]);
		}
		printf("...\t\t\t\t ...\n");

		//////// C KERNEL ////////
		call_c_kernel(vecsize, A_testscalar, X_testvec, Y_testvec, Z_resultvec);

		//////// ASM KERNEL ////////
		call_asm_kernel(vecsize, A_testscalar, X_testvec, Y_testvec, Z_resultvec);
		

	return 0;
}


void call_c_kernel(int n, float A, float X[], float Y[], float Z[]) {
	printf("\n==================== C KERNEL RESULTS ====================\n");
	clock_t start;
	clock_t diff;
	int time_taken;
	int avg_time;
	// Run C Kernel 30 times and then time average
	avg_time = 0;
	for (int i = 0; i < testcount; i++) {
		start = clock();
		saxpy_c(n, A, X, Y, Z);	// CALL C KERNEL (saxpy_c.c)
		diff = clock() - start;
		time_taken = diff * 1000 / CLOCKS_PER_SEC;
		avg_time = avg_time + time_taken;
	}
	avg_time = avg_time / testcount;

	// Print Results 
	printf("\nC Kernel Vector Z (1st 10):\n");
	for (int i = 0; i < 10; i++) {
		printf("%.3f\n", Z_resultvec[i]);
	}
	printf("...\n");
	printf("\nC Kernel Avg. Runtime (30 loops) : %d milliseconds\n", avg_time % 1000);
}



void call_asm_kernel(int n, float A, float X[], float Y[], float Z[]) {
	printf("\n=================== ASM KERNEL RESULTS ===================\n");
	clock_t start;
	clock_t diff;
	int time_taken;
	int avg_time;
	// Run C Kernel 30 times and then time average
	avg_time = 0;
	for (int i = 0; i < testcount; i++) {
		start = clock();
		saxpy_asm(n, A, X, Y, Z);	// CALL ASM KERNEL (saxpy_asm.asm)
		diff = clock() - start;
		time_taken = diff * 1000 / CLOCKS_PER_SEC;
		avg_time = avg_time + time_taken;
	}
	avg_time = avg_time / testcount;

	// Print Results 
	printf("\nASM Kernel Vector Z (1st 10):\n");
	for (int i = 0; i < 10; i++) {
		printf("%.3f\n", Z_resultvec[i]);
	}
	printf("...\n");
	printf("\nASM Kernel Avg. Runtime (30 loops) : %d milliseconds\n", avg_time % 1000);


}