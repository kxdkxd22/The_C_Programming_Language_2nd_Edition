#include<stdio.h>

int my_strindex(char *s,char *t);

main(){
	
	char *s ="1234567890";
	char *t = "90";

	printf("%d\n",my_strindex(s,t));

}

int my_strindex(char *s,char *t){
	char *p, *r;
	char *bs = s;
	for(;*s!='\0';s++){
		for(p=s,r=t;*r!='\0'&&*p==*r;p++,r++)
			;
		if(r>t&&*r == '\0')
			return s-bs;
	}

	return -1;

}
