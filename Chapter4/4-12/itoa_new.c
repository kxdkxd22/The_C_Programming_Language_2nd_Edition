#include<stdio.h>
#include<math.h>
#include<ctype.h>

void itoa(int n,char s[]);

main(){

	char s[1024];
	
	itoa(1234,s);
	printf("%s\n",s);
}


void itoa(int n,char s[]){
	static int i=0;
	if(n/10){
		itoa(n/10,s);
	}else{
		//i = 0;
		if(n<0)
			s[i++] = '-';
	}
	s[i++] = abs(n)%10+'0';
	s[i] = '\0';
}

