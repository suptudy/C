#include <stdio.h>

int main() {
	int x, y, interval, i;
	int d = 1;
	int start = 1;
	int end = 1;
	scanf("%d %d", &x, &y);
	interval = y-x;
	for(i=1;;i++) {
		if(start<=interval&&interval<=end){
			printf("%d\n", i);
			return 0;
		}
		if(i%2==0)
			d++;
		start = end+1;
		end = start+d-1;
	}
	return 0;
}
