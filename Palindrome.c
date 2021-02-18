#include <stdio.h>
#include <string.h>

int isPalindrome(char *string, int start, int end);

int main() {
	int answer;
	char string[100];
	scanf("%s", string);
	answer = isPalindrome(string, 0, strlen(string)-1);
	if(answer==1)
		printf("YES");
	else
		printf("NO");
	return 0;
}
int isPalindrome(char *string, int start, int end) {
	printf("start %d end %d\n", start, end);
	if(start==end)
		return 1;
	else if(start+1==end){
		if(string[start]==string[end])
			return 1;
		else 
			return 2;
	}else{
		if(string[start]==string[end]){
			return isPalindrome(string, start+1, end-1);
		}else
			return 2;
	}
}
