#include<stdio.h>
#include<ctype.h>

#define BUFSIZE 100
#define SIZE 10

int buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);


main(){
	int n,array[SIZE],getint(int *);
	int i = 0;

	for(n=0;n<SIZE&&getint(&array[n])!=EOF;n++)
		;
	for(i = 0; i<n;i++)
			printf("%d\n",array[i]);
}


int getint(int *pn){
	int c,sign,d;

	while(isspace(c=getch()))
		;

	if(!isdigit(c)&&c!=EOF&&c!='+'&&c!='-'){
		ungetch(c);
		return 0;
	}

	sign = (c=='-')?-1:1;

	if(c == '+'||c == '-'){
		d = c;
		if(!isdigit(c = getch())){
			if(c!=EOF)
				ungetch(c);
			ungetch(d);
			return d;
		}

	}
		
	for(*pn = 0; isdigit(c);c = getch())
		*pn = 10* *pn+(c-'0');

	*pn *= sign;
	 
	if(c!=EOF){
		ungetch(c);
	}
	return c;
}

int getch(void){

	return (bufp>0)?buf[--bufp]:getchar();

}

void ungetch(int c){
	if(bufp>=BUFSIZE){
		printf("ungetch: too many character\n");
	}else
		buf[bufp++] = c;

}
