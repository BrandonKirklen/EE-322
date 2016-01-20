#include <stdio.h>

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main(int argc, char *argv[]) {
	int test = map(50,0,100,0,1000);
	
	printf("%i", test);
}