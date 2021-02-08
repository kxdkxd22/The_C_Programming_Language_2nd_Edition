#include<stdio.h>

int my_strncmp(char *s,char *t,int n);

main(){

	char s[1024] = "1234567890";
	char t[1024] = "12345fafafaa";

	printf("%d\n",my_strncmp(s,t,6));
}


int my_strncmp(char *s,char *t,int n){
	
	for(;n-->0&&*s==*t;s++,t++)
		if(*s == '\0'|| n == 0)
			return 0;

	return *s-*t;
}
