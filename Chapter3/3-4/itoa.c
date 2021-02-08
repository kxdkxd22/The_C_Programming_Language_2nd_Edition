#include<stdio.h>
#include<string.h>

void my_itoa(int n,char s[]);
void reverse(char s[]);

main(){
	
	char s[1024];
	my_itoa(-2147483648,s);
	printf("%s\n",s);
}

void my_itoa(int n,char s[]){

	int i,sign;
	
	sign = n;
	i = 0;

	do{
		s[i++] = abs(n%10)+'0';
	}while(n/=10);
	
	if(sign < 0)
		s[i++] = '-';
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
