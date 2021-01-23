#include <stdio.h> //PA13
#include <time.h>
#include <stdlib.h>
void mine(int *np, int *mp);
void minesweeper(char **basenum, int rows, int cols); 

int n,m;
void main() {
	scanf("%d %d", &n, &m);
	mine(&n, &m);
}

void mine(int *np, int *mp) {
	char *base[*np]; // 행, 포인터배열(포인터들을 모아둠) 
	int i, j, k;
	srand((unsigned)time(NULL));
	int boomRow, boomCol; 
	
	for(i=0;i<*np;i++) { //열, 각 행(포인터마다)1차원 배열 동적할당  
		base[i] = (char*)malloc((*mp)*sizeof(char)); 
		if(base[i] != NULL) {
			for(j=0;j<*mp;j++) {
			base[i][j] = '.';
			}
		}
	}

	for(k=0;k<*np;k++) { // 최대 *np개의 지뢰 생성  
		boomRow = rand()%(*np);
		boomCol = rand()%(*mp);
		base[boomRow][boomCol] = '*';	
	} //난수를 생성하여 임의의 위치에 지뢰 생성  
	
	for(i=0;i<*np;i++) { //확인용 
		for(j=0;j<*mp;j++) {
			printf("%c ", base[i][j]);
		}
		printf("\n");
	}
	
	//포인터배열과 행열 넘김  
	minesweeper(base, *np, *mp); 
}

void minesweeper(char **basenum, int rows, int cols) {
	int r, c, x, y, f;
	int count = 0;
	
	printf("---- MINESWEEPER ----\n");
	for(r=0;r<rows;r++) {
		for(c=0;c<cols;c++) {
			if(basenum[r][c] == '*') { //지뢰는 숫자변환X 
				printf("%c ", basenum[r][c]); 
				continue;
			} else { // 현재의 주변 check  
				for(y=r-1;y<=r+1;y++) { //현재(5)를 중심으로 7,8,9 
					for(x=c-1;x<=c+1;x++) { //현재(5)를 중심으로 4,6 
						if(y<0||x<0||y>=rows||x>=cols) { //현재(5)를 중심으로 1,2,3
							continue;
						} else if(basenum[y][x] == '*') {
							count = count+1; 
						}
					}
				}
				basenum[r][c] = count;
				printf("%d ", basenum[r][c]);
				count = 0;
			}
		}
		printf("\n");
	}
	
	for(f=0;f<rows;f++) {
		free(basenum[f]);  
	} 
}


