#include <stdio.h>

int main() {
  int i, n;
  int cnt = 0;
  scanf("%d", &n);
  int arr[n];
  int check[n+1];
  if(n<6) {
  	printf("NO\n");
  	return 0;
  }
  for(i=0;i<n+1;i++) {
    check[i] = 0;
  }
  for(i=1;i<=n;i++) {
    scanf(" %d", &arr[i]);
    check[arr[i]]+=1;
  }
  for(i=1;i<=n;i++) {
    if(check[i]>2){
    	check[i] = 2; //최대 2개 사용 가능 
    	cnt += check[i];
	}else{
		cnt += check[i];
	}
  }
  //printf("cnt: %d\n", cnt);
  if(cnt >= 6){
    printf("YES\n");
  }else{
  	printf("NO\n");
  }
  return 0;
}
