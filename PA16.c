#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000001

char max_alphabet(char string[]);

int main() { 
	char str[MAX];
	char found;
	
	gets(str);
	if(strlen(str)<=1000001) {
		found = max_alphabet(str);	
	}
	printf("%c\n", found);
	return 0;
}

char max_alphabet(char string[]) { //함수인자포인터(배열) 사용  
	int i, j, m, n;
	int length = strlen(string);
	int count[26];
	int result;
	
	for(i=0;i<26;i++) {
		count[i] = 0;
	}

	for(j=0;*(string+j) != '\0'; j++) {
		if('a'<=*(string+j) && *(string+j)<='z') {
			*(string+j) = *(string+j) - 32;  
		}
		count[*(string+j)-'A']++;
	}	

	for(m=1; m<26; m++) {
		if(count[result] < count[m]) {
			result = m;
		} 
	}
	
	for(n=result+1; n<26; n++) {
		if(count[result] == count[n]) {
			result = '?';
		}
	}
	
	if(result != '?') {
		return result + 'A';
	} else {
		return result;
	}	 
}
