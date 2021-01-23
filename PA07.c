#include <stdio.h>

void print_prime(long long *np, long long *mp) {
	long long i;
	long long max = *np+*mp; 
	
	for( ; *np<=max; (*np)++) {
		for(i=2; i<=*np; i++) { 
			if(*np % i == 0) {
				break;
			}			
		}
		if(*np==i) {
				printf("%lld\n", *np);
			}
	}
}

void main() {
	long long n,m;
	
	printf("Enter N and M: ");
	scanf("%lld", &n);
	scanf("%lld", &m);
	
	print_prime(&n, &m);
}
