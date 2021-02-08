#include<stdio.h>
#include<stdarg.h>
#include<ctype.h>

#define LOCALFMT 100

void miniprintf(char *fmt,...);

main(){
	miniprintf("char*:%s int:%d float:%f 0x:%x\n","hello world",520,520.0,0xff);

}

void miniprintf(char *fmt,...){

	va_list ap;
	char *p,*sval;
	char localfmt[LOCALFMT];
	int i,ival;
	unsigned uval;
	double dval;
	
	va_start(ap,fmt);
	for(p=fmt;*p;p++){
		if(*p!='%'){
			putchar(*p);
			continue;
		}
		
		i=0;
		localfmt[i++] = *p;
		
		while(*(p+1)&&!isalpha(*(p+1)))
			localfmt[i++]=*++p;
		localfmt[i++] = *(p+1);
		localfmt[i] = '\0';
		
		switch(*++p){
			case 'i':
			case 'd':
				ival = va_arg(ap,int);
				printf(localfmt,ival);
				break;
			case 'X':
			case 'x':
			case 'o':
			case 'u':
				uval = va_arg(ap,unsigned);
				printf(localfmt,uval);
				break;
			case 'f':
				dval = va_arg(ap,double);
				printf(localfmt,dval);
				break;
			case 's':
				sval = va_arg(ap,char *);
				printf(localfmt,sval);
				break;
			default:
				printf(localfmt);
				break;
		}
	}
	va_end(ap);
}
