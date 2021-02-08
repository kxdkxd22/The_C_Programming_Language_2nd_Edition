#include<stdio.h>
#include<ctype.h>

#define BUFSIZE 100
#define SIZE 10

int buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);


main(){
	int n;
	double array[SIZE];
	int getfloat(double *);
	int i = 0;

	for(n=0;n<SIZE&&getfloat(&array[n])!=EOF;n++)
		;
	for(i = 0; i<n;i++)
			printf("%f\n",array[i]);
}


int getfloat(double *pn){
	int c,sign,d;
	double power;

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
		*pn = 10.0 * *pn+(c-'0');
	
	if(c == '.'){
		c = getch();
	}
	
	for(power = 1.0; isdigit(c); c= getch()){
		*pn = 10.0* *pn+(c-'0');
		power*=10.0;
	}

	*pn = sign * *pn/power;
	 
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
