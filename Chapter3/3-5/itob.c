#include<stdio.h>
#include<string.h>

void itob(int n,char s[],int b);
void reverse(char s[]);

main(){
	
	char s[1024];
	itob(1024,s,16);
	
	printf("%s\n",s);


}

void itob(int n,char s[],int b){

	int i,sign;
	i = 0;
	if((sign=n)<0){
		n = -n;
	}
	int c;
	do{
		c = n%b;	
		s[i++] = (c<=9)?c+'0':c+'a'-10;
	}while((n/=b)>0);	
	
	if(sign<0){
		s[i++] = '-';
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

