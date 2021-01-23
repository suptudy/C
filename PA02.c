#include <stdio.h>

void sort3(int *x, int *y, int *z) {
	int temp;
	
	if(*x > *y) {
		temp = *x;
		*x = *y;
		*y = temp;
	} 
	
	if(*x > *z) {
		temp = *x;
		*x = *z;
		*z = temp;
	} 
	
	if(*y > *z) {	
		temp = *y;
		*y = *z;
		*z = temp;
	}
}

void main() {
	int x=0, y=0, z=0;
	
	puts("Enter three integer numbers (x, y, z)");
	printf("x: "); scanf("%d", &x);
	printf("y: "); scanf("%d", &y);
	printf("z: "); scanf("%d", &z);
	
	sort3(&x, &y, &z);
	
	printf("[Sorted Result] %d %d %d", x, y, z);
}
