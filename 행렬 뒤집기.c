#include <stdio.h>

int main() {
	int i, j, n;
	int map[10][10] = {0, };
	scanf("%d" ,&n);
	for(i=0;i<10;i++) {
		for(j=0;j<10;j++) {
			scanf("%d ", &map[i][j]);
		}
	}
	for(i=0;i<n;i++) { //row
		for(j=0;j<10;j++) {
			if(map[i][j] == 0) {
				map[i][j] = 1;
			}else {
				map[i][j] = 0;
			}
		}
	}
	for(i=0;i<10;i++) { //col
		for(j=0;j<n;j++) {
			if(i==j)
				continue;
			if(map[i][j] == 0) {
				map[i][j] = 1;
			}else {
				map[i][j] = 0;
			}
		}
	}
		
	for(i=0;i<10;i++) {
		for(j=0;j<10;j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
