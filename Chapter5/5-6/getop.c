#include<stdio.h>
#define NUMBER '0'
#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int c);

main(){

	char s[1024];
	while(getop(s))
		printf("%s",s);

}


int getop(char *s){
	int c;
	while((*s = c =getch())==' '|| c =='\t')
		;
	*(s+1) = '\0';
	if(!isdigit(c)&&c!='.')
		return c;
	if(isdigit(c))
		while(isdigit(*++s = c = getch()))
			;
	*s = '\0';
	if(c!=EOF)
		ungetch(c);
	return NUMBER;
}
int getch(void){

	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c){
	if(bufp>=BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}


