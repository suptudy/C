#include <stdio.h>
#include <string.h>
#include <stdlib.h>   
char** changeAlpha(char** change, int m);
void waldorf(char** base, char **find, int m, int n, int k);

void main() {
	int i,m,n,k;
	int count = 0;
	char *rows[50];
	char *finds[20];
	//printf("INPUT:\n");
	scanf("%d %d", &m, &n);
	
	if((1<=m)&&(m<=50)&&(1<=n)&&(n<=50)) {
		for(i=0;i<=m;i++) {
			rows[i] = (char*)malloc(n*sizeof(char));
			if((rows[i] != NULL) && (count++<n)) {
				gets(rows[i]);
			}
		}
		changeAlpha(rows, m);
	}
	
	//printf("k�Է�\n");
	scanf("%d", &k);
	
	if((1<=k)&&(k<=20)) {
		for(i=0;i<=k;i++) {
			finds[i] = (char*)malloc(k*sizeof(char));
			if(finds[i] != NULL) {
				gets(finds[i]);
			}
		}
		changeAlpha(finds, k);
	}
	
	waldorf(rows, finds, m, n, k); 
	
	for(i=0;i<=m;i++) {
		free(rows[i]);
	}  
	for(i=0;i<=k;i++) {
		free(finds[i]);
	}
}

char** changeAlpha(char** change, int m) {
	int i,j;
	
	for(i=1;i<=m;i++) {
		for(j=0;*(change[i]+j) != '\0'; j++) {
			if('a'<=*(change[i]+j) && *(change[i]+j)<='z') {
				*(change[i]+j) = *(change[i]+j) - 32;  
			} //�ҹ��� -> �빮��
			if(*(change[i]+j)<'A'||'Z'<*(change[i]+j)) {
					return 0;
			} //�ܾ �Է��� ���� �빮�ڿ� �ҹ��ڹۿ� �� �� ����. 
		}    
	}

	return change;
}

void waldorf(char** base, char **find, int m, int n, int k) {
	int br,bc,fr,fc,x,y,length;
	int count;
	
	//printf("\nOUTPUT:\n");
	for(fr=1;fr<=k;fr++) {
		for(br=1;br<=m;br++) {
			for(bc=0;bc<n;bc++) {
				if(base[br][bc] == find[fr][0]) {
					length = strlen(find[fr]);
					if(br >= length) { //�� (br�� 1���� �����ϹǷ� +1����) 
						count = 0;
						for(fc=0;fc<length;fc++) {
							if(find[fr][fc] == base[br-fc][bc]) {  
								count++;
								if(count == length) 
									printf("%d %d\n", br, bc+1);		
							}
						}
					}
					
					if(bc+1 >= length) { //�� (bc�� 0���� �����ϹǷ� +1) 
						count= 0;
						for(fc=0;fc<length;fc++) {
							if(find[fr][fc] == base[br][bc-fc]) {
								count++;
								if(count == length) 
									printf("%d %d\n", br, bc+1);		 
							}
						}
					}
					
					if(n-bc >= length) { //�� 
						count = 0;
						for(fc=0;fc<length;fc++) {
							if(find[fr][fc] == base[br][bc+fc]) {
								count++;
								if(count == length)
									printf("%d %d\n", br, bc+1);
							}
						}
					}
					
					if(m-(br-1) >= length) { //�Ʒ�  
						count= 0;
						for(fc=0;fc<length;fc++) {
							if(find[fr][fc] == base[br+fc][bc]) {
								count++;
								if(count == length)
									printf("%d %d\n", br, bc+1);
							}
						}
					}
					
					if((br >= length) && (bc+1 >= length)) { //��, �� 
						count = 0;
						for(fc=0;fc<length;fc++) {
							if(find[fr][fc] == base[br-fc][bc-fc]) {
								count++;
								if(count == length) 
									printf("%d %d\n", br, bc+1);
							}
						} 
					}
				
					if((br >= length) && (n-bc >= length)) { //��, �� 
						count = 0;
						for(fc=0;fc<length;fc++) {
							if(find[fr][fc] == base[br-fc][bc+fc]) {
								count++;
								if(count == length) 
									printf("%d %d\n", br, bc+1);
							}
						} 
					}
				
					if((m-(br-1) >= length) && (bc+1 >= length)) { //�Ʒ�, �� 
						count = 0;
						for(fc=0;fc<length;fc++) {
							if(find[fr][fc] == base[br+fc][bc-fc]) {
								count++;
								if(count == length) 
									printf("%d %d\n", br, bc+1);
							}
						} 
					}
				
					if((m-(br-1) >= length) && (n-bc >= length)) {//�Ʒ�, �� 
						count = 0;
						for(fc=0;fc<length;fc++) {
							if(find[fr][fc] == base[br+fc][bc+fc]) {
								count++;
								if(count == length) 
									printf("%d %d\n", br, bc+1);
							}
						} 
					}	 
				}
			}	
		}	
	}	
}




