#include <stdio.h>

void print_array(int *ip, int n) {
	for(int i=0; i<n; i++) {
		printf("%d ", *(ip+i)+1);
	}
				
}

void main() {
	int iarr[5] = {10, 20, 30, 40, 50};
	
	print_array(iarr, 5);
}
