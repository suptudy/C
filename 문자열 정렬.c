#include <stdio.h>
#include <string.h>

int main() {
  int i, j, n, index;
  scanf("%d", &n);
  char temp[101];
  char words[n][101];
  for(i=0;i<n;i++) {
    scanf("%s", &words[i]);
  }
  for(i=0;i<n-1;i++) {
    for(j=0;j<n-1-i;j++) {
      if(strcmp(words[j], words[j+1])>0){
        strcpy(temp, words[j]);
        strcpy(words[j], words[j+1]);
        strcpy(words[j+1], temp);
      }
    }
  }
  for(i=0;i<n;i++) {
    printf("%s\n", words[i]);
  }
  return 0;
}
