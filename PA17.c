#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
void anagram(char *anag[100], int caseNum);

void main() { //PA17
	int i,j, result;
	int caseNum;
	char *casetest[100] = {NULL,}; 
	
	scanf("%d", &caseNum);
	
	if(caseNum > 100) {
		return; //케이스 개수 100넘으면 강제 종료  
	}	

	for(i=0; i<=caseNum; i++) {
		casetest[i] = (char*)malloc(sizeof(char)*100);
		if(casetest[i] != NULL) {
			gets(casetest[i]);	
		} 
	}
	
	anagram(casetest, caseNum);
	
	for(j=0; j<=caseNum; j++) {
		free(casetest[j]);
	}
}

void anagram(char *anag[100], int caseNum) {
	int i, j, k, m, t, length1, length2;
	int count1[caseNum+1][26];
	int count2[caseNum+1][26];
	int result[caseNum+1];
	char *test1[100] = {NULL,}; 
	char *test2[100] = {NULL,};
	char collect1[50];
	char collect2[50];  
	
	for(j=0; j<=caseNum; j++) {
		for(i=0; i<26; i++) {
			count1[j][i] = 0;
			count2[j][i] = 0;
		}
		result[j] = 0;	
	}
	
	for(j=1; j<=caseNum; j++) { 
		test1[j] = strtok(*(anag+j), " ");
		test2[j] = strtok(NULL, "\n");
		
		length1 = strlen(test1[j]);
		length2 = strlen(test2[j]); 
		
		strcpy(collect1, test1[j]);
		for(k=0;*(collect1+k) != '\0'; k++) {
			if('a'<=*(collect1+k) && *(collect1+k)<='z') {
				*(collect1+k) = *(collect1+k) - 32;  
			} else {
				return; //소문자 아니면 강제 종료 
			}
			count1[j][*(collect1+k)-'A']++;
		}
		
		strcpy(collect2, test2[j]);
		for(k=0;*(collect2+k) != '\0'; k++) {
			if('a'<=*(collect2+k) && *(collect2+k)<='z') {
				*(collect2+k) = *(collect2+k) - 32;  
			} else {
				return; //소문자 아니면 강제 종료 
			}
			count2[j][*(collect2+k)-'A']++;
		}
	}	
	
	for(t=1; t<=caseNum; t++) {
		for(m=0; m<26; m++) {
			if(count1[t][m] != count2[t][m]) {
				result[t] = 1;
				printf("%s & %s are NOT anagrams.\n", test1[t], test2[t]);
				break;
			}	
		}
		if(result[t] != 1) {
			printf("%s & %s are anagrams.\n", test1[t], test2[t]);
		}	 
	}
}









