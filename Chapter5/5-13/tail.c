#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLEN 100
#define MAXLINES 5000

int my_getline(char s[],int);

main(int argc,char *argv[]){
	int n=10;
	if(argc == 2){
		if(*argv[1]=='-'){
			n = atoi(++argv[1]);
		}
	}
	
	char *lineptr[MAXLINES];
	int len,nlines;
	char *p,line[MAXLEN];	
	
	nlines = 0;
	while((len=my_getline(line,MAXLEN))>0){
		if(nlines>=MAXLINES||(p=(char*)malloc(len))==NULL)
			return;
		else{
			line[len-1] = '\0';
			strcpy(p,line);
			lineptr[nlines++] = p;
		}
		
	}

	int i;
	i = nlines - n;
	
	i = (i>=0)?i:0;
	
	while(i<nlines){
		printf("%s\n",lineptr[i++]);
	}

}

int my_getline(char s[],int lim){
	int c,i;
	i = 0;
	while(--lim>0&&(c=getchar())!=EOF&&c!='\n')
		s[i++] =c;
	if(c=='\n')
		s[i++] = '\0';
	s[i] = '\0';
	return i;

}	
