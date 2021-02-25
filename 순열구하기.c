#include <stdio.h>
void getResult(int x);
 
// 전역변수 선언
int n, r;
int result[26]; 

int main() {
	scanf("%d %d", &n, &r);
	getResult(0);
	return 0;
}

void getResult(int x) { //r중for문 생성  
	int i, j;
	int flag = 0; 
	if(x >= r){
		//중복 유무 확인 
		for(i=0;i<r;i++) {
			for(j=0;j<r;j++) {
				if(i!=j && result[i]==result[j]){
					flag = 1;
				}
			}
		}
		if(flag == 0){ //중복 없음 
			for(i=0;i<r;i++){
				printf("%c ", result[i]+97);
			} 
			printf("\n");
		}
	}else{
		for(i=0;i<n;i++){
			result[x] = i;
			getResult(x+1);
		}
	}
}
