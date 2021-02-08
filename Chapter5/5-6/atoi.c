#include<stdio.h>

int atoi(char *s);

main(){
	char s[1024] = "123456";
	printf("%d\n",atoi(s));

}

int atoi(char *s){
	int n,sign;

	for(;isspace(*s);s++)
		;
	sign = (*s == '-')?-1:1;
	if(*s == '+' || *s == '-')
		s++;
	for(n = 0;isdigit(*s);s++)
		n = 10*n+(*s-'0');
	return sign*n;
}
