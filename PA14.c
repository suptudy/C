#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
						//투표를 할 때 아무것도 입력하지 않고 개행하면 당선자나옴!!
int voteStart(int cand);
int* voteArrange1(int *first, int voteCount, int candAcc);

void main() {
	int n=0;
	int electName = 0;	
	int i;
	char name[n][81]; 
	//printf("후보자 수를 입력하세요\n");
	scanf("%d", &n);
	 
	//printf("후보자 명단을 입력하세요\n");
	for(i=0;i<=n;i++) {
		gets(name[i]);
	}
	printf("\n"); 

	electName = voteStart(n);
	printf("%s", name[electName]);
	
}

int voteStart(int cand) {
	int i,j,k,s,b,max,min,maxCand;
	int q=0;
	int minCand[20];
	int voteCount = 0;
	int count = 0;
	char *vote[1000];  
	char *temp1[1000] = {NULL,};  
	int voteN[][1000] = {0,}; 
	int countAcc[cand];
	//printf("투표를 시작합니다\n");
	for(i=1;i<=1000;i++) {   
		vote[i] = (char*)malloc(sizeof(char)*cand); 
		if(vote[i] != NULL) {
			gets(vote[i]);
			if(*vote[i] == 0) {
				break;
			} else {
				voteCount++; 
			}
		}
	}
	
	for(k=1;k<=voteCount;k++) {  
		temp1[k] = strtok(vote[k], " ");
		voteN[1][k] = atoi(temp1[k]);
 
		for(j=2;j<=cand;j++) {
			temp1[k] = strtok(NULL, " ");
			voteN[j][k] = atoi(temp1[k]);	
		} 
	}  
	
	for(i=0;i<=voteCount;i++) { 
		countAcc[(voteN[1][i])] = countAcc[(voteN[1][i])] +1;
	}	
	
	max = countAcc[1];
	min = countAcc[1];
	for(i=1;i<=cand;i++) {
	 	if(max < countAcc[i]) 
	 		max = countAcc[i];
		if(min > countAcc[i]) 
			min = countAcc[i]; 
	}
	for(j=1;j<=cand;j++) {
	 	if(countAcc[j] == max) 
	 		maxCand = j;
		else if(countAcc[j] == min) 
		 	minCand[j] = j;	 	
	}
	
	int *elect = voteArrange1(countAcc, voteCount, cand);
	for(i=0;i<=cand;i++) {
		countAcc[i] = 0; 
	}

	for(j=1;j<=cand;j++) { 
		if(*(elect+j) == minCand[j]) {

			for(s=1;s<=voteCount;s++) {
				if(voteN[1][s] == *(elect+j)) {
					b = voteN[2][s];
					count++;
					while(q!=count) {
						countAcc[q+1] = b;
						q++;
					}
				}
			}
			if(j == cand) { 
				voteArrange1(countAcc, voteCount, cand);
			}	
		} else {
			for(i=1;i<=1000;i++) {
				free(vote[i]);
			}
			return *elect;
		}
	}
} 

int* voteArrange1(int *first, int voteCount, int candAcc) {  
	int i,j, max, min;
	static int maxCand[1];
	static int minCand[20];
	static int memory[20];
	max = first[1];
	min = first[1];
	for(i=1;i<=candAcc;i++) {
	 	if(max < first[i]) 
	 		max = first[i];
		if(min > first[i]) 
			min = first[i]; 
	}
	for(j=1;j<=candAcc;j++) {
	 	if(first[j] == max) {
	 		if(memory[j] != -1) {
	 			maxCand[0] = j;
	 			memory[j] = memory[j] + *(first+j);
	 			max = memory[j];
			 }
		} else if(first[j] == min) {
			minCand[j] = j;
		 	if(minCand[j] != 0 || memory[j] == -1) {
		 		first[minCand[j]] = -1; 
				memory[j] = -1;
			}
		}
	}
 
	if(max>(voteCount/2)) {  
	 	return maxCand;
	} else { 
		return minCand;   
	} 	 
}
