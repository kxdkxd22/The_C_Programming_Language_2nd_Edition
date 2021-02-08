#include<stdio.h>
#include"calc.h"

#define MAXVAL 100
int sp = 0;

double val[MAXVAL];

void push(double f){
	if(sp < MAXVAL){
		val[sp++] = f;
	}else
		printf("error: stack full, can't push %g\n",f);

}

double pop(void){
	if(sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}

double top(void){

	if(sp>0){
		return val[sp-1];
					
	}else{
		printf("error: stack empty\n");
		return 0.0;
	}
	
}

void duplicate_top(void){

	double topval = pop();
	
	push(topval);
	push(topval);

}

void swap(void){
	
	double tmp1 = pop();
	double tmp2 = pop();

	push(tmp1);
	push(tmp2);
	
}


void clear(void){

	sp = 0;
}









