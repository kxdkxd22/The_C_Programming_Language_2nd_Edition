#include<stdio.h>

char s[1024];
int i = 0;
void itoa(int n);

main(){
	itoa(12345);
	printf("%s\n",s);
}


void itoa(int n){

	if(n<0){
		s[i++] = '-';
		n = -n;
	}

	if(n/10)
		itoa(n/10);
	
	s[i++] = n%10+'0';
	s[i] = '\0';
	
}
