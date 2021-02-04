#include <stdio.h>

int main() {
	int i, j, n, x, y, r, ux, uy;
	scanf("%d", &n);
	int map[n][n];
	scanf("%d %d %d", &x, &y, &r);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			map[i][j] = 0; //초기화 
		}
	}
	x--;
	y--; //x와 y , map index 0부터 시작
	ux = x;
	uy = y;
	map[ux][uy] = 'x'; 
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(i-x<0)
				ux = -(i-x);
			else
				ux = i-x;
			if(j-y<0)
				uy = -(j-y);
			else 
				uy = j-y;
			if(0<ux+uy&&ux+uy<=r)
				map[i][j] = ux+uy;
		}
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(i==x&&j==y)
				printf("%c ", map[i][j]);
			else
				printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
