#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"calc.h"

#define MAXLINE 100
char line[MAXLINE];
int li = 0;
int my_getline(char line[],int limit);

int getop(char s[]){

	int i,c;
	
	if(line[li]=='\0'){
		if(my_getline(line,MAXLINE)==0){
			return EOF;
		}else
			li = 0;

	}
	
	while((s[0]=c=line[li++])==' '||c == '\t')
		;
	s[1]='\0';
	i=0;
	
	if(islower(c)){
		while(islower(s[++i]=c=line[li++]))
			;
		s[i] = '\0';
		if(c!=EOF)
			li--;
		if(strlen(s)>1)
			return NAME;
		else 
			return c;
	}

	if(!isdigit(c)&&c!='.'&&c!='-'){
		return c;
	}else if(c == '-'){
		if(isdigit(c=line[li++])||c=='.'){
			s[++i] = c;
		}else{
			if(c!=EOF)
				li--;
			return '-';
		}

	}

	if(isdigit(c)){
		while(isdigit(s[++i]=c=line[li++]))
			;
	}

	if(c == '.')
		while(isdigit(s[++i]=c=line[li++]))
			;

	s[i] = '\0';
	
	if(c!=EOF){
		li--;
	}

	return NUMBER;
}

int my_getline(char s[],int lim){
	int c,i;
	i = 0;
	while(--lim>0&&(c=getchar())!=EOF&&c!='\n')
		s[i++]=c;
	if(c=='\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

