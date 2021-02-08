#include<stdio.h>
#include<string.h>

void reverse(char *s);
void itoa(int n,char *s);

main(){
        char s[1024];
        itoa(-123456,s);
        printf("%s\n",s);

}

void itoa(int n,char *s){
	int sign;
	char *bs =s;
	if((sign = n)<0)
		n = -n;
	do{
		*s++ = n%10+'0';
	}while((n/=10)>0);
	if(sign<0)
		*s++ = '-';
	*s = '\0';
	reverse(bs);
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



