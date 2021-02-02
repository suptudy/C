#include <stdio.h>
int main() {
	int i, row, col, rookR, rookC, kingR, kingC, result;
	int rookNum = 0;
	int chess[8][8];
	int rook[2][2] = {0, };//rook[i][0]=rookR rook[i][1]=rookC 
	for(row=0;row<8;row++) {
		scanf("%d %d %d %d %d %d %d %d", &chess[row][0], &chess[row][1], &chess[row][2], &chess[row][3], &chess[row][4], &chess[row][5], &chess[row][6], &chess[row][7]);	
	}
	for(row=0;row<8;row++) {
		for(col=0;col<8;col++) {
			if(chess[row][col]==2){
				rook[rookNum][0] = row;
				rook[rookNum][1] = col;
				rookNum++;
			}else if(chess[row][col]==1){
				kingR = row;
				kingC = col;	
			}		
		}
	}
	//printf("rook1 R %d C %d\n king R %d C %d\n", rook[0][0], rook[0][1], kingR, kingC);
	//printf("rook2 R %d C %d\n", rook[1][0], rook[1][1]);
	for(i=0;i<2;i++) {
		rookR = rook[i][0];
		rookC = rook[i][1];
		if(rookR==kingR||rookC==kingC) { //같은 행이나 열
			if(kingR>rookR){ //down
				for(rookR;rookR<9;rookR++) {
					if(chess[rookR][rookC]==3){
						result = 0;
						break;
					}else if(chess[rookR][rookC]==1){
						result = 1;
						break;
					}
				}
			}else if(kingR<rookR){ //up
				for(rookR;0<=rookR;rookR--) {
					if(chess[rookR][rookC]==3){
						result = 0;
						break;
					}else if(chess[rookR][rookC]==1){
						result = 1;
						break;	
					}
				}	
			}else if(kingC<rookC){ //left
				for(rookC;0<=rookC;rookC--) {
					if(chess[rookR][rookC]==3){
						result = 0;
						break;
					}else if(chess[rookR][rookC]==1){
						result = 1;
						break;
					}
				}
			}else if(kingC>rookC){ //right
				for(rookC;rookC<9;rookC++) {
					if(chess[rookR][rookC]==3){
						result = 0;
						break;
					}else if(chess[rookR][rookC]==1){
						result = 1;
						break;	
					}
				}
			}
		}else{
			result = 0; 
		}
		if(result==1)
			break;
	}
	printf("%d\n", result);
	return 0;
}
