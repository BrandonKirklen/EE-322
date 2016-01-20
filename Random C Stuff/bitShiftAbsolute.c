#include <stdio.h>

int bitshiftabsolute(int value);

int bitshiftabsolute(int value){
	int mesh = value >> 31;
	return (value ^ mesh) - mesh;
}

int main(int argc, char *argv[]) {
	int test1 = 1;
	int test2 = -4;

	printf("Initial Value: %i Function Value: %i \n", test1, bitshiftabsolute(test1));
	printf("Initial Value: %i Function Value: %i \n", test2, bitshiftabsolute(test2));
}