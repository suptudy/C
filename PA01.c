#include <stdio.h>

void sum_diff_mul(int x, int y, int *sum, int *diff, int *mul) {
	*sum = x+y;
	*diff = x-y;
	*mul = x*y;
}

void main() {
	int x=0, y=0;
	int sum=0, diff=0, mul=0;
	
	puts("Enter two integer numbers (x, y)\n");
	printf("x: "); scanf("%d", &x);
	printf("y: "); scanf("%d", &y);
	
	sum_diff_mul(x, y, &sum, &diff, &mul);
	
	printf("SUM: %d, DIFF: %d, MUL: %d\n", sum, diff, mul);
}
