#include<stdio.h>

void my_strcat(char *s,char *t);

main(){

	char s[1024] = "asdfg";
	char t[1024] = "wqewr";

	my_strcat(s,t);
	printf("%s\n",s);

}

void my_strcat(char *s,char *t){

	for(;*s!='\0';s++)
		;
	while((*s++ = *t++)!='\0')
		;

}
