#include<stdio.h>

void my_strncat(char *s,char *t,int n);

main(){
	char s[1024] = "adsadsdad";
	char t[1024] = "1234567890";

	my_strncat(s,t,5);
	printf("%s\n",s);
}


void my_strncat(char *s,char *t,int n){
	char *bs =s;
	while(*s)
		s++;
	while(*t && n-- > 0)
		*s++ = *t++;
	*s = '\0';	
}
