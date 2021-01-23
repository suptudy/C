#include <stdio.h>    
#include <string.h> 
#include <stdlib.h>

void right(char *now2, int cnt2, char string[]);
void left(char *now1, int cnt1, int stairs, char string[]);
char stradd(char *dext, char *src);

int main() {
	int n, i;
	char answer[] = "";
	
	printf("How many steps do you want: ");
	scanf("%d", &n);
	
	for(i=3; i>=1; i--) {
		char answer[] = ""; 
		left(&n, i, i, answer);
		printf("\n");   
	}
	right(&n, 1, answer);
}

char stradd(char *dest, char *src) {
	while(*dest) {
		dest++;
	}
	while(*src) {
		*dest =*src;
			src++;
			dest++;
	}
	*dest='\0';
		return 1;
}

void left(char *now1, int cnt1, int stairs, char string[]) {  
	int leg = stairs; 
	char stairs_s[] = "";
	itoa(leg,stairs_s,10); 
	char answer[] = "";  
		
	if(*now1 < cnt1) {
		return;
	} else if(*now1==cnt1) {
		stradd(string, stairs_s);   
		printf("%sL", string);
		return; 
	} else {
		if(atoi(string)>1) {
			printf("\n1R, ");	 
		} 
		if(string != '\n') {
		string[0] = '\0';   
		}
		stradd(string, stairs_s);
		printf("%sL, ", string);	
	}	
	right(now1, cnt1+1, answer);	
}

void right(char *now2, int cnt2, char string[]) {
	int i,j;
	char answer[] = "";  
	int now_a = *now2; 

	if(*now2<cnt2) {
		return;
	} else if(*now2==cnt2) {
		printf("%s", "1R");
		return; 
	} else {
		printf("%s", "1R, ");
	}

	for(i=3; i>=1; i--) {
		left(now2, cnt2+i, i, answer);
	}
}

