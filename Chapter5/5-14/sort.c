#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLEN 100
#define MAXLINES 5000
#define NUMERIC 1
#define DECR 2

char *lineptr[MAXLINES];

int my_getline(char s[],int);

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines,int decr);

void my_qsort(void *lineptr[],int left,int rigtht,int (*comp)(void *,void *));
int numcmp(char *,char *);

main(int argc,char *argv[]){
	
	int c,nlines;
	int option = 0;

	while(--argc>0&&(*++argv)[0]){
		while(c=*++argv[0]){
			switch(c){
			case 'n':
				option|=NUMERIC;
				break;
			case 'r':
				option|=DECR;
				break;
			}
		}
	}

	if((nlines = readlines(lineptr,MAXLINES))>=0){
		if(option&NUMERIC){
			my_qsort((void **)lineptr,0,nlines-1,(int (*)(void *,void *))(numcmp));
		}else
			my_qsort((void **)lineptr,0,nlines-1,(int (*)(void *,void *))(strcmp));
		writelines(lineptr,nlines,(option&DECR));
		return 0;
	}else{
		printf("input too big to sort\n");
		return 1;
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

int readlines(char *lineptr[],int maxlines){
	int len,nlines;
	char *p,line[MAXLEN];
	nlines = 0;
	while((len=my_getline(line,MAXLEN))>0){
		if(nlines>=maxlines||(p=(char *)malloc(len))==NULL)
			return -1;
		else{
			line[len-1] = '\0';
			strcpy(p,line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void writelines(char *lineptr[],int nlines,int decr){
	int i;
	if(decr){
		for(i=nlines-1;i>=0;i--)
			printf("%s\n",lineptr[i]);
	}else{
		for(i=0;i<nlines;i++)
			printf("%s\n",lineptr[i]);
	}
	
}

void my_qsort(void *v[],int left,int right,int(*comp)(void *,void *)){
	int i,last;
	void swap(void *v[],int ,int);

	if(left>=right)
		return;

	swap(v,left,(left+right)/2);
	last = left;
	
	for(i=left+1;i<=right;i++)
		if((*comp)(v[i],v[left])<0)
			swap(v,++last,i);
	swap(v,left,last);
	my_qsort(v,left,last-1,comp);
	my_qsort(v,last+1,right,comp);
}	


void swap(void *v[],int i,int j){
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;

}

int numcmp(char *s1,char *s2){
	double v1,v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if(v1< v2)
		return -1;
	else if(v1 >v2)
		return 1;
	else
		return 0;
}











