#include<stdio.h>

void my_strncpy(char *s,char *t,int n);

main(){
	char s[1024];
	char t[1024] = "1234567890";
	
	my_strncpy(s,t,5);
	printf("%s\n",s);
}


void my_strncpy(char *s,char *t,int n){
	while(*t&&n-->0)
		*s++ = *t++;
	*s='\0';
}
