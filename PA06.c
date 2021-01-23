#include <stdio.h>

void convert2decimal(int *ip) {
	int i, j;
	int arr[8], decimal;  // �迭�� �� �ڸ� ���ڸ� �־���  
	int *iparr;
	iparr = arr;
	
	*(iparr+7) = *ip / 10000000;
	*(iparr+6) = *ip % 10000000 / 1000000;
	*(iparr+5) = *ip % 10000000 % 1000000 / 100000;
	*(iparr+4) = *ip % 10000000 % 1000000 % 100000 / 10000;
	*(iparr+3) = *ip % 10000000 % 1000000 % 100000 % 10000 / 1000;
	*(iparr+2) = *ip % 10000000 % 1000000 % 100000 % 10000 % 1000 / 100;
	*(iparr+1) = *ip % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 / 10;
	*(iparr+0) = *ip % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 % 10 / 1;

	int number(int n) {
		if(n==0)
			return 1;
		return number(n-1) * 8;
	} // 8�� n�� �������  
	
	for(i=0; i<8; i++) {
		*(iparr+i) = *(iparr+i) *number(i);
	} // �� �ڸ� ���ڿ� ����ġ 8�� i���� ������  
	
	for(j=0; j<8; j++) {
		decimal = decimal + *(iparr+j);
	} // �� �ڸ� ���ڿ� ����ġ 8�� ���� ���� �� ���� 10������ ���� ���� decimal 
	
	if(*ip>77777777) {
		printf("UNABLE TO CONVERT");
	} else {
		printf("%d:%d\n", *ip, decimal);	
	}
}

void main() {
	int octal;
	
	printf("Enter up to an 8-digit octal number: ");
	scanf("%d", &octal);
	
	convert2decimal(&octal);
}
