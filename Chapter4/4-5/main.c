#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"calc.h"

#define MAXOP 100

void mathfnc(char s[]);

main(){

	int type;
	double op2;
	char s[MAXOP];
	
	while((type = getop(s))!=EOF){
		switch(type){
		case NUMBER:
			push(atof(s));
			break;
		case NAME:
			mathfnc(s);
			break;
		case '+':
			push(pop()+pop());
			break;
		case '*':
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
		case '%':
			op2 = pop();
			if(op2!=0.0)
				push(fmod(pop(),op2));
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n",pop());
			break;
		default:
			printf("error: unknown command %s\n",s);
			break;
		}				
	}
	return 0;
}

void mathfnc(char s[]){

	double op2;

	if(strcmp(s,"sin")==0){
		push(sin(pop()));
	}else if(strcmp(s,"cos")==0){
		push(cos(pop()));
	}else if(strcmp(s,"exp")==0){
		push(exp(pop()));
	}else if(strcmp(s,"pow")==0){
		op2 = pop();
		push(pow(pop(),op2));
	}else{
		printf("error: %s not supported\n");
	}
}



