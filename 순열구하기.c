#include <stdio.h>
void getResult(int x);
 
// �������� ����
int n, r;
int result[26]; 

int main() {
	scanf("%d %d", &n, &r);
	getResult(0);
	return 0;
}

void getResult(int x) { //r��for�� ����  
	int i, j;
	int flag = 0; 
	if(x >= r){
		//�ߺ� ���� Ȯ�� 
		for(i=0;i<r;i++) {
			for(j=0;j<r;j++) {
				if(i!=j && result[i]==result[j]){
					flag = 1;
				}
			}
		}
		if(flag == 0){ //�ߺ� ���� 
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
