#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define NUMBER '0'
#define BUFSIZE 100

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

int getop(char *);
void push(double);
double pop(void);

main(int argc,char *argv[]){

	int i,type;
	double op2;
	
	for(i=0;i<argc-1&&(type=getop(*++argv))!='\0';i++){
		switch(type){
		case NUMBER:
			push(atof(*argv));
			break;
		case '+':
			push(pop()+pop());
			break;
		case 'x':
			push(pop()*pop());
			break;
		case '-':
			op2 = pop();
			push(pop()-op2);
			break;
		case '/':
			op2 = pop();
			if(op2!=0.0)
				push(pop()/op2);
			else
				printf("error: zero divisor\n");
			break;
		default:
			printf("error: unknown command %s\n",t);
			break;
			 
		}

	}
	printf("\t%.8g\n",pop());
	return 0;

}


int getop(char *s){
	int c;
	if(*s == '\0'){
		return '\0';
	}
	c=*s;
	if(!isdigit(c)&&c!='.')
		return c;
	return NUMBER;
}

void push(double f){

	if(sp<MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n",f);
}

double pop(void){
	if(sp>0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}










