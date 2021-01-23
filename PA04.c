#include <stdio.h>

void convert2octal(int *ip) {
	int i, j;
	int arr[5], octal; // �迭�� �� �ڸ� ������ ������ �־���  
	int *iparr;
	iparr = arr;
	
	*(iparr+0) = *ip % 8;
	*(iparr+1) = *ip / 8 % 8;
	*(iparr+2) = *ip / 8 / 8 % 8;
	*(iparr+3) = *ip / 8 / 8 / 8 % 8;
	*(iparr+4) = *ip / 8 / 8 / 8 / 8;
	
	int number(int n) {
		if(n == 0)
			return 1;
		return number(n-1) * 10;
	} // 10�� n�� �������  
	
	for(i=0; i<5; i++) {
		*(iparr+i) = *(iparr+i) * number(i);
	} // �������� �� �ڸ� ���ڿ� �°� ������ 10�� i���� ������  
	
	for(j=0; j<5; j++) {
		octal = octal + *(iparr+j);
	} // �� ���� 8������ ���� ���� octal
	
	if(*ip > 32767) {
		printf("UNABLE TO CONVERT\n");
	} else {
		printf("%d:%d\n", *ip, octal);
	}		
}

void main() {
	int decimal;
	
	printf("Please enter a number between 1 and 32767 to convert: ");
	scanf("%d", &decimal);
	
	convert2octal(&decimal);
}
