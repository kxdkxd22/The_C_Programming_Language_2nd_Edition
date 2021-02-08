#include<stdio.h>
#include<string.h>

void itoa(int n,char s[],int w);
void reverse(char s[]);

main(){
	char s[1024];
	itoa(255,s,10);
	printf("%s\n",s);
	itoa(255,s,8);
	printf("%s\n",s);
}


void itoa(int n,char s[],int w){

	int i,sign;
	
	sign = n;
	i = 0;

	do{
		s[i++] = abs(n%10)+'0';	

	}while((n/=10)!=0);
	
	if(sign < 0){
		s[i++] = '-';
	}
	
	while(i<w){
		s[i++] = ' ';
	}

	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]){
	int c,i,j;

	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

}
