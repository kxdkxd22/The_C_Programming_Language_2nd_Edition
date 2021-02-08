#include<stdio.h>
#include<string.h>
#define MAXLINES 5000

char *lineptr[MAXLINES];
char linestor[4096];

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);

main(){
	int nlines;
	if((nlines=readlines(lineptr,MAXLINES))>=0){
		writelines(lineptr,nlines);
		return 0;
	}else{
		printf("error: input too big\n");
		return 1;
	}

}

#define MAXLEN 1000
int my_getline(char *,int);

int readlines(char *lineptr[],int maxlines){
	int len,nlines;
	char line[MAXLEN];
	static char *p = linestor;

	nlines = 0;
	while((len=my_getline(line,MAXLEN))>0)
		if(nlines>=maxlines||(p+len)>=(linestor+4096)){
			return -1;
		}else{
			line[len-1] = '\0';
			strcpy(p,line);
			lineptr[nlines++] = p;
			p=p+len;
		}

	return nlines;
}

void writelines(char *lineptr[],int nlines){
	int i;
	for(i = 0; i < nlines; i++)
		printf("%s\n",lineptr[i]);
}

int my_getline(char *s,int lim){
	int c,i;
	i=0;
	while(--lim>0 &&(c=getchar())!=EOF&&c!='\n'){
		*s++ = c;
		i++;
	}
	if(c == '\n'){
		*s++ = c;
		i++;
	}
	*s = '\0';
	return i;
}
