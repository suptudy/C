#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 255
int word_count(char* string);

void main() {
	//동적메모리 할당을 이용하여 입력되는 문자열을 위한 공간 확보
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

int word_count(char* string) { //입력된 문자열을 받음  
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
