#include<stdio.h>
/*#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){

	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c){
	
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
	
}*/
char buf = 0;

int getch(void){
	int c;
	
	if(buf != 0){
		c = buf;
	}else{
		c = getchar();
	}
	buf = 0;
	return c;
}

void ungetch(int c){
	if(buf!=0){
		printf("ungetch: too many character\n");
	}else{
		buf = c;
	}

}

void ungets(char s[]){
	int i;
	for(i=0;s[i]!='\0';i++){
		ungetch(s[i]);
	}

}

