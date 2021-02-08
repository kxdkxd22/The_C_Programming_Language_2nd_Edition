#include<stdio.h>

char s[1024];

void escape(char s[],char t[]);
void unescape(char s[],char t[]);

main(){
	
	int i;
	char t[1024],c;

	for(i=0;i<1024&&(c=getchar())!=EOF;i++){
		t[i] = c;	
	}

	t[i] = '\0';
	
	escape(s,t);
	printf("%s\n",s);
	char un_s[1024];
	unescape(un_s,s);
	printf("%s\n",un_s);

}

void escape(char s[],char t[]){
	int i,j;
	for(i=j=0;t[i]!='\0';i++){
		switch(t[i]){
			case '\n':
				s[j++]='\\';
				s[j++]='n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}
	s[j] = '\0';
	
}

void unescape(char c[],char t[]){
	
	int i,j;
	for(i=j=0;t[i]!='\0';i++){
		if(t[i]=='\\'){
			i++;
		}
		
		switch(t[i]){
			case 'n':
				c[j++]= '\n';
				break;
			case 't':
				c[j++] = '\t';
				break;
			default:
				c[j++] = t[i];
				break;

		}
	}

	c[j] = '\0';
		
}	


