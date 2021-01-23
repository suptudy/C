#include <stdio.h> 

void processSieve(int *primeLimit);
void getBoundaries();
void showPrimes();

int sexyPrimes[] = {};

void main() {
	getBoundaries();
}

void getBoundaries() {
	int i,j,lower, upper;
	int range[2]; 
	for(i=1;;i++) {
		printf("Please enter the lower boundary (between 1 and 50000) : ");
		scanf("%d", &lower);
		
		if(lower<1 || lower>50000) {
			continue;
		} else {
			for(j=1;;j++) {
				printf("Please enter the upper boundary (between 1 and 50000) : ");
				scanf("%d", &upper);
				
				if(upper<1 || upper>50000) {
					continue;
				} else if(lower>upper) { 
					printf("Your upper boundary cannot be smaller than your lower boundary\n");
				} else {
					break;
				}

				if(0<upper && upper<50001) {
					break;
				} else {
					break;	
				}	
			}
			
			if((0<lower && lower<50001) && lower>upper) {
				continue;
			} else { 
				range[0] = lower, range[1] = upper; 
				processSieve(range);
				break;
			}
		}
		break;
	}	
}
  
void processSieve(int *primeLimit) { //소수찾는 알고리즘:소수는 1, 소수가 아닌것들은 2 
	int p=0;
	int a,i,j,h,k;
	int primes[50001]; 
	int rangeLow = *primeLimit;
	int rangeHigh = *(primeLimit+1);
	int total = sizeof(primes)/sizeof(primes[0]);
	
	for(k=0;k<50001;k++) {
		primes[k] = 1;
	} 
	
	primes[0] = 2;
	primes[1] = 2;
  
	for(i=2;i*i<=total;i++) { 
		if(primes[i] != 2) {  
			for(j=i*i;j<=total;j+=i) {
				primes[j] = 2;		
			}  
		}  
	} 
	 
	for(h=rangeLow;h<=rangeHigh;h++) {
		if(primes[h] != 2) {   
			sexyPrimes[p] = h;   
			p++;
		}
	}
	
	printf("Here are all of the sexy prime pairs in the range %d to %d\n", rangeLow, rangeHigh);
	showPrimes();
	printf("%d and %d",rangeLow, rangeHigh);	
}

void showPrimes() { 
	int pairnum,i;
	int count = 0;
  
	for(pairnum=0;pairnum<300;pairnum++) {
		if(sexyPrimes[pairnum+1] - sexyPrimes[pairnum]== 6) {  
			if(sexyPrimes[pairnum+1] == 0) { 
				break;
			}
			printf("%d and %d\n", sexyPrimes[pairnum], sexyPrimes[pairnum+1]); 
			count++;
		} else { 
			for(i=1;;i++) {
				if(sexyPrimes[pairnum+1+i] - sexyPrimes[pairnum]== 6) {  
					if(sexyPrimes[pairnum+1] == 0) { 
						break;
					}
					printf("%d and %d\n", sexyPrimes[pairnum], sexyPrimes[pairnum+1+i]);
					count++;
				}else {  
					break;
				}
			} 
		}
	}
	printf("There were %d sexy prime pairs displayed between ", count);
}


