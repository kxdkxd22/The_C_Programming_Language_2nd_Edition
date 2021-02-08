#include<stdio.h>
#include<string.h>

void reverse(char *s);

main(){
	char s[1024] = "asdfghjk";
	reverse(s);
	printf("%s\n",s);

}


void reverse(char *s){
	char *t;
	char c;
	for(t=s+strlen(s)-1;s<t;s++,t--){
		c= *s;
		*s = *t;
		*t = c; 
	}

}
