#include<stdio.h>
#define MAXLINE 1000

int get_line(char line[],int maxline);
void reverse(char s[]);

main(){

	char line[MAXLINE];
	
	while(get_line(line,MAXLINE)>0){
		reverse(line);
		printf("%s",line);
	}

}

int get_line(char s[],int lim){

	int c,i;
	
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
		s[i]=c;
	}

	if(c == '\n'){
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;

}

void reverse(char s[]){
	int i,j;
	
	char temp;
	i = 0;
	
	while(s[i]!='\n'){
		++i;
	}	

	--i;
	if(s[i] == '\n'){
		--i;
	}

	j = 0;
	while(j<i){
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		--i;
		++j;
	}

}














