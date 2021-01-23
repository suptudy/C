#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_date(char* birthday);
int validate_date(int year, int month, int day);
void crunch_date(int number);
void show_numerolgy(int number); 

void main() {
	char info[14];  

	printf("Enter the birth date (mm/dd/yyyy): ");
	scanf("%[^\n]s", info); // �Է¹��� ������ �迭�� ����, ���� ����� ���� [^\n]  

	get_date(info);
}

void get_date(char *birthday) {
	//�⵵, ��, �Ϸ� �����Ͽ� ó��
	int index = 0;  
	int i = 0, j = 0;
	int month, day, year, number;
	char *infos[3] = {NULL, }; // ������ �迭�� NULL�� �ʱ�ȭ   
	
	for( ; index<=strlen(birthday); index++) {
		if(('0'<=*(birthday+index) && *(birthday+index)<='9')) { //������ ��
			if(('0'<=*(birthday+index+1) && *(birthday+index+1)<='9')|| *(birthday+index+1) == ' ' || (index+1) == strlen(birthday)) {
				//���� ������ �����̰ų� �����̰ų� NULL�� ��  
				//pass
			} else {
				printf("Use spacebar between mm/dd/yyyy!\n");
				return;
			}
		} else if(*(birthday+index) == ' ') { // ������ ��  
			if(('0'<=*(birthday+index+1) && *(birthday+index+1)<='9') || *(birthday+index+1) == '/') { // ���� ������ ���� �̰ų� �������� ��  
				//pass
			} else {
				printf("Use forward slashes between mm/dd/yyyy!\n");
				return;
			}if(('0'<=*(birthday+index+1) && *(birthday+index+1)<='9')) { // ���� ������ ������ �� 
				//pass
			} else if (*(birthday+index) == '/') { //�������� �� 
			if(*(birthday+index+1) == ' ') { //������ ������ ������ ��  
				//pass
			} else {
				printf("Use spacebar between mm/dd/yyyy!\n");
				return;
				}
			}	
		}
	}
	
	char *info = strtok(birthday, " "); 
	while(info != NULL) {	
		infos[i] = info;
		i++;  	
		info = strtok(NULL,"/ ");	
	} //infos �迭�� ��, ��, �� ���� �ֱ�  
	  
	month = atoi(infos[0]);
	day = atoi(infos[1]);
	year = atoi(infos[2]); // ���ڿ��� ���ڷ� �ٲٱ�
	
	number = validate_date(year, month, day); //validate_date�� return���� number�� ����  
	crunch_date(number);
}

int validate_date(int year, int month, int day) {
	int number;
  
	if(year<1880 || year>2280) {   
		printf("Bad year: %d\n", year);  
		return -1; 
	}
	if(month<1 || month>12) {
		printf("Bad month: %d\n", month);
		return -1;
	}
	int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if(year%4 == 0) {
		if(year%100 == 0) {
			if(year%400 == 0) {
				monthDays[2] = 29;
			}  
		} else {
				monthDays[2] = 29;
			}
	} //���⿡ ���� 2���� ������ ��  
	
	if(day > monthDays[month]) {
		printf("Bad day for %d/%d : %d\n",month, year, day);
		return -1;
	} else {
		printf("Welcome to the numerology report for %d/%d/%d:\n:", month, day, year);
		number =  year + month + day; 
		return number; 		
	}
}

void crunch_date(int number) {
	int result = 0;
	
	while(number != 0) {
	result = result + (number%10); 
	number = number / 10;
	} // �Է��� ���� �ɰ� �� �ڸ� ���ڷ� �ٲ� ���Ѵ�

	if(result > 9) { //���� ���� ���ڸ��� ���  
		result = (result/10) + (result%10);	
	}	

	show_numerolgy(result);	
}

void show_numerolgy(int number) {

	switch(number) {
		case 0:
			printf("0: You are on the rigth path.\n");
			break;
		case 1:
			printf("1: Neither gice cherries to pigs nor advice to a fool.\n");
			break;
		case 2:
			printf("2: Expect harmony and balance.\n");
			break;
		case 3: 
			printf("3: Your dearest dream is coming true.\n");
			break;
		case 4:
			printf("4: Take a leap if faith.\n");
			break;
		case 5: 
			printf("5: Your sweetheart may be too beautiful for words, but not for\narguements.");
			break;
		case 6:
			printf("6: Rid your life of negative energy.\n");
			break;
		case 7: 
			printf("7: Prepare for a spiritual awakening.\n");
			break;
		case 8:
			printf("8:You are almost there.\n");
			break;
		case 9:
			printf("9: Share your wisdom with the world.\n");
	}
}
