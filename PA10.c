#include <stdio.h>
#include <string.h>

int testPerfect(int *num1);
void printFactors(int *num2);

void main() {
	int i,j,n1, n2;
	for(i=1;;i++) {
		printf("How many numbers would you like to test? ");
		scanf("%d", &n1);
		for(j=1;j<=n1;j++) {
			printf("\n");
			printf("Please enter a possible perfect number: ");
			scanf("%d", &n2);
			
			if(testPerfect(&n2) == 1) {  //완전수O
				printFactors(&n2);
				if(n1 == j) {
					return;
				} 
				continue;
			} else { //완전수X  
				printf("%d:NOT PERFECT\n", n2);
				if(n1 == j) {
					return;
				} 
				continue; 
			} 
			break;
		}
	}
}

int testPerfect(int *num1) {  
	int j;
	int sub = 0;
	
	for(j=1;j<=*num1;j++) {
		if(*num1%j==0) { //num의 약수들 j  
			if(*num1 != j) {
				sub = sub + j;
			} else {
				if(*num1 == sub) {
					return 1;
				} else {
					return 0;
				}
			} 			
		}
	}
}

void printFactors(int *num2) {   
	int j,k;
	int *perfect;    
	printf("%d:", *num2);
	for(j=1;j<=*num2;j++) {
		if(*num2%j==0) {  
			perfect = j;  
			if(j != *num2) {
				printf("%d ", perfect); 
			}
		}	
	}
	printf("\n");
}
