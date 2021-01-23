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
	char *base[*np]; // ��, �����͹迭(�����͵��� ��Ƶ�) 
	int i, j, k;
	srand((unsigned)time(NULL));
	int boomRow, boomCol; 
	
	for(i=0;i<*np;i++) { //��, �� ��(�����͸���)1���� �迭 �����Ҵ�  
		base[i] = (char*)malloc((*mp)*sizeof(char)); 
		if(base[i] != NULL) {
			for(j=0;j<*mp;j++) {
			base[i][j] = '.';
			}
		}
	}

	for(k=0;k<*np;k++) { // �ִ� *np���� ���� ����  
		boomRow = rand()%(*np);
		boomCol = rand()%(*mp);
		base[boomRow][boomCol] = '*';	
	} //������ �����Ͽ� ������ ��ġ�� ���� ����  
	
	for(i=0;i<*np;i++) { //Ȯ�ο� 
		for(j=0;j<*mp;j++) {
			printf("%c ", base[i][j]);
		}
		printf("\n");
	}
	
	//�����͹迭�� �࿭ �ѱ�  
	minesweeper(base, *np, *mp); 
}

void minesweeper(char **basenum, int rows, int cols) {
	int r, c, x, y, f;
	int count = 0;
	
	printf("---- MINESWEEPER ----\n");
	for(r=0;r<rows;r++) {
		for(c=0;c<cols;c++) {
			if(basenum[r][c] == '*') { //���ڴ� ���ں�ȯX 
				printf("%c ", basenum[r][c]); 
				continue;
			} else { // ������ �ֺ� check  
				for(y=r-1;y<=r+1;y++) { //����(5)�� �߽����� 7,8,9 
					for(x=c-1;x<=c+1;x++) { //����(5)�� �߽����� 4,6 
						if(y<0||x<0||y>=rows||x>=cols) { //����(5)�� �߽����� 1,2,3
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


