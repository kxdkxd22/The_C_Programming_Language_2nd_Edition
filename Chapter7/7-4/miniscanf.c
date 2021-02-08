#include<stdio.h>
#include<stdarg.h>
#include<ctype.h>

#define LOCALFMT 100

void miniscanf(char *fmt,...);

main(){
	char s[1024];
	int i;
	float f;
	
	miniscanf("%s %d %f\n",s,&i,&f);
	
	printf("char*:%s int:%i float:%lf\n",s,i,f);
}

void miniscanf(char *fmt,...){

	va_list ap;
	char *p,*sval;
	char localfmt[LOCALFMT];
	int i,*ival;
	unsigned *uval;
	double *dval;
	
	va_start(ap,fmt);
	for(p=fmt;*p;p++){
		i=0;
		if(*p!='%'){
			localfmt[i++]=*p;
			continue;
		}
		
				
		localfmt[i++] = *p;
		
		while(*(p+1)&&!isalpha(*(p+1)))
			localfmt[i++]=*++p;
		localfmt[i++] = *(p+1);
		localfmt[i] = '\0';
		
		switch(*++p){
			case 'i':
			case 'd':
				ival = va_arg(ap,int*);
				scanf(localfmt,ival);
				break;
			case 'X':
			case 'x':
			case 'o':
			case 'u':
				uval = va_arg(ap,unsigned*);
				scanf(localfmt,uval);
				break;
			case 'f':
				dval = va_arg(ap,double*);
				scanf(localfmt,dval);
				break;
			case 's':
				sval = va_arg(ap,char *);
				scanf(localfmt,sval);
				break;
			default:
				scanf(localfmt);
				break;
		}
	}
	va_end(ap);
}
