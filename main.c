#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern void asmhello(); 
// Has to be the same name as in .ASM file (extern)

int main() {
	asmhello(); // SASM file is a function
	return 0;
}