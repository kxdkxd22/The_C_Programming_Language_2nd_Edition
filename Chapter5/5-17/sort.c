#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXLEN 100
#define MAXLINES 5000
#define MAXSTR 100
#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define DDIR 8

static int option = 0;
int pos1 = 0;
int pos2 = 0;

char *lineptr[MAXLINES];

int my_getline(char s[],int);

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines,int decr);

void my_qsort(void *lineptr[],int left,int rigtht,int (*comp)(void *,void *));
int numcmp(char *,char *);
int charcmp(char *,char *);
void readargs(int argc,char *argv[]);

void substr(char *s,char *str);

main(int argc,char *argv[]){
	
	int c,nlines;

	readargs(argc,argv);

	if((nlines = readlines(lineptr,MAXLINES))>=0){
		if(option&NUMERIC)
			my_qsort((void **)lineptr,0,nlines-1,(int (*)(void *,void *))(numcmp));
		else
			my_qsort((void **)lineptr,0,nlines-1,(int (*)(void *,void *))(charcmp));
		
		writelines(lineptr,nlines,(option&DECR));
		return 0;
	}else{
		printf("input too big to sort\n");
		return 1;
	}
	
}

void readargs(int argc,char *argv[]){
	int c;
	
	while(--argc>0&&(c=(*++argv)[0])=='-'||c=='+'){
                if(c == '-'&& isdigit(*(argv[0]+1)))
		while(c=*++argv[0]){
                        switch(c){
                        case 'n':
                                option|=NUMERIC;
                                break;
                        case 'r':
                                option|=DECR;
                                break;
                        case 'f':
                                option|=FOLD;
                                break;
                        case 'd':
                                option|=DDIR;
                                break;
                        }
                }
		
		else if(c == '-')
			pos2 = atoi(argv[0]+1);
		else if(c == '+')
			pos1 = atoi(argv[0]+1);
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

void substr(char *s,char *str){
	int i,j,len;

	extern pos1,pos2;
	
	len = strlen(s);
	
	if(pos2>0&&len>pos2){
		len = pos2;
	}
	
	for(j=0,i=pos1; i<len;j++,i++){
		str[j] = s[i];
	}
	str[j] = '\0';
}

int numcmp(char *s1,char *s2){
	double v1,v2;

	char str[MAXSTR];
	substr(s1,str);
	v1 = atof(str);

	substr(s2,str);
	v2 = atof(str);

	if(v1< v2)
		return -1;
	else if(v1 >v2)
		return 1;
	else
		return 0;
}


int charcmp(char *s1,char *s2){
	
	char a,b;
	
	int fold = option&FOLD;	
	int dir = option&DDIR;
	int i,j,endpos;
	
	i=j=pos1;
	if(pos2>0)
		endpos = pos2;
	else 
		endpos = (strlen(s1)>strlen(s2))?strlen(s2):strlen(s1);

	do{
		if(dir){
			while(!isalnum(s1[i])&&s1[i]!=' '&& s1[i]!='\0')
				i++;
			while(!isalnum(s2[j])&&s2[j]!=' '&& s2[j]!='\0')
                                j++;
		}
		
		a = (fold)?tolower(s1[i]):s1[i];
		i++;
		b = (fold)?tolower(s2[j]):s2[j];
		j++;
		
		if(a==b&&a=='\0'){
			return 0;
		}
	}while(a==b&&i<endpos&&j<endpos);	

	return a-b;
}








