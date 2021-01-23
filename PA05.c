#include <stdio.h>

void get_fibonacci(int *ip) {
	int i = 0;
	long long arr[71];
	arr[0] = 0, arr[1] = 1;
	
	for(i=2; i<=*ip; i++) {
		arr[i] = arr[i-1] + arr[i-2];
	}
	printf("%d:%lld\n", *ip, *(arr+*ip));
}  

void main() {
	int num;
	
	while(1) {
		printf("Which Fobonacci number would you like?: ");
		scanf("%d", &num);
		if(num >0 && num <=70) 
			break;
	}
	get_fibonacci(&num);
}
