#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int reverse_add(int *num);
void swap(char *a, char *b);
int isPalindrome(int numPal);

void main() {
	int n,i, result;
	int count = 0;

	printf("[출력예시에서 원하는 부분]Please enter a number: ");
	scanf("%d", &n); 
	if(isPalindrome(n) != 0) { 
		//처음에 입력한 값이 회문이면	
		printf("[출력예시에서 원하는 부분1]%d %d // 반복횟수는 %d, 찾아진 회문의 수는 %d\n",count, n, count, n);
		return; 
	} else { //처음에 입력한 값이 회문이 아니면
		result = reverse_add(&n);  
		isPalindrome(result); 
		if(isPalindrome(result) == 0) { //회문이면 
			count++;
		} else {  
			count++; 
			printf("[출력예시에서 원하는 부분2]%d %d // 반복횟수는 %d, 찾아진 회문의 수는 %d\n",count, result, count, result);
			return;
		} 
	}
	
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<OUT OF FOR\n"); 
	for(i=0;i<5;i++) {
		result = reverse_add(&result); //result 는 숫자  
		
		if(isPalindrome(result) == 0) { //회문이 아니면 
			printf("회문이 아닙니다\n");
			count++;
			continue;
		}else { //회문이면 
			printf("회문입니다\n");
			count++;   
			printf("[출력예시에서 원하는 부분3]%d %d // 반복횟수는 %d, 찾아진 회문의 수는 %d\n",count, result, count, result);
			break;
		}
		break;	
	}
} 
int isPalindrome(int numPal) { //숫자값을 받아오는  
	char check[10]; //테스트 데이터들은 최대 10자리 수  
	int checkLength,i;
	int isPal;
	isPal = numPal;
	itoa(isPal,check,10); //숫자를 문자로
	checkLength = strlen(check);

	for(i=0;i<checkLength/2;i ++) {
		if(check[i] != check[checkLength-1-i]) { //왼 오 문자 다르면 
			return 0; 
		} else {
			return 1;	
		}
	}		
}

int reverse_add(int *num) {    
	int shakeResult,i,length;
	char shake0[10];
	char shake1[] = ""; //들어온값을 거꾸로 만든 값
	itoa(*num,shake0,10); //*num값을 숫자에서 문자로  
	strcpy(shake1, shake0); 
	length = strlen(shake1); 

	for(i=0;i<length/2;i++) { //문자열 인덱싱 역순 
		swap(&shake1[i], &shake1[length-i-1]);
	}

	shakeResult = *num + atoi(shake1);
	printf("num %d shake1 %d\n",*num, atoi(shake1)); //숫자와 숫자 덧셈  
	printf("==============[R : %d]============\n", shakeResult); //회문  
	 	
	return shakeResult;
}

void swap(char *a, char *b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
} 

