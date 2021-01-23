#include <stdio.h>

void convert2octal(int *ip) {
	int i, j;
	int arr[5], octal; // 배열에 각 자리 숫자의 나머지 넣어줌  
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
	} // 10의 n승 만들어줌  
	
	for(i=0; i<5; i++) {
		*(iparr+i) = *(iparr+i) * number(i);
	} // 나머지가 각 자리 숫자에 맞게 들어가도록 10의 i승을 곱해줌  
	
	for(j=0; j<5; j++) {
		octal = octal + *(iparr+j);
	} // 다 더해 8진수를 만든 것이 octal
	
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
