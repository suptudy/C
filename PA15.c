#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 255
int word_count(char* string);

void main() {
	//�����޸� �Ҵ��� �̿��Ͽ� �ԷµǴ� ���ڿ��� ���� ���� Ȯ��
	char* str = (char*)malloc(MAX_LENGTH+1);
	int nword = 0;
	
	printf("Enter a string: ");
	if(str != NULL) {
		gets(str);	
	}
	
	nword = word_count(str);
	printf("%d\n", nword); 
	free(str); 
}

int word_count(char* string) { //�Էµ� ���ڿ��� ����  
	int i;
	int space = 0;
	int word = 0;
	int length = strlen(string);
	
	for(i=0;i<length;i++) {
		if(string[i] == ' ') {
			space++;
		}
	}
	
	word = space + 1;
	return word;
}
