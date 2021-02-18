#include <stdio.h>
int getMount(int n);

int main(){
	int n;
	scanf("%d", &n);
	getMount(n);
	return 0;
}

int getMount(int n){
	if(n==1){
		printf("1");
	}else{
		getMount(n-1);
		printf("%d", n);
		getMount(n-1);
	}
}
