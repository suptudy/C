#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int reverse_add(int *num);
void swap(char *a, char *b);
int isPalindrome(int numPal);

void main() {
	int n,i, result;
	int count = 0;

	printf("[��¿��ÿ��� ���ϴ� �κ�]Please enter a number: ");
	scanf("%d", &n); 
	if(isPalindrome(n) != 0) { 
		//ó���� �Է��� ���� ȸ���̸�	
		printf("[��¿��ÿ��� ���ϴ� �κ�1]%d %d // �ݺ�Ƚ���� %d, ã���� ȸ���� ���� %d\n",count, n, count, n);
		return; 
	} else { //ó���� �Է��� ���� ȸ���� �ƴϸ�
		result = reverse_add(&n);  
		isPalindrome(result); 
		if(isPalindrome(result) == 0) { //ȸ���̸� 
			count++;
		} else {  
			count++; 
			printf("[��¿��ÿ��� ���ϴ� �κ�2]%d %d // �ݺ�Ƚ���� %d, ã���� ȸ���� ���� %d\n",count, result, count, result);
			return;
		} 
	}
	
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<OUT OF FOR\n"); 
	for(i=0;i<5;i++) {
		result = reverse_add(&result); //result �� ����  
		
		if(isPalindrome(result) == 0) { //ȸ���� �ƴϸ� 
			printf("ȸ���� �ƴմϴ�\n");
			count++;
			continue;
		}else { //ȸ���̸� 
			printf("ȸ���Դϴ�\n");
			count++;   
			printf("[��¿��ÿ��� ���ϴ� �κ�3]%d %d // �ݺ�Ƚ���� %d, ã���� ȸ���� ���� %d\n",count, result, count, result);
			break;
		}
		break;	
	}
} 
int isPalindrome(int numPal) { //���ڰ��� �޾ƿ���  
	char check[10]; //�׽�Ʈ �����͵��� �ִ� 10�ڸ� ��  
	int checkLength,i;
	int isPal;
	isPal = numPal;
	itoa(isPal,check,10); //���ڸ� ���ڷ�
	checkLength = strlen(check);

	for(i=0;i<checkLength/2;i ++) {
		if(check[i] != check[checkLength-1-i]) { //�� �� ���� �ٸ��� 
			return 0; 
		} else {
			return 1;	
		}
	}		
}

int reverse_add(int *num) {    
	int shakeResult,i,length;
	char shake0[10];
	char shake1[] = ""; //���°��� �Ųٷ� ���� ��
	itoa(*num,shake0,10); //*num���� ���ڿ��� ���ڷ�  
	strcpy(shake1, shake0); 
	length = strlen(shake1); 

	for(i=0;i<length/2;i++) { //���ڿ� �ε��� ���� 
		swap(&shake1[i], &shake1[length-i-1]);
	}

	shakeResult = *num + atoi(shake1);
	printf("num %d shake1 %d\n",*num, atoi(shake1)); //���ڿ� ���� ����  
	printf("==============[R : %d]============\n", shakeResult); //ȸ��  
	 	
	return shakeResult;
}

void swap(char *a, char *b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
} 

