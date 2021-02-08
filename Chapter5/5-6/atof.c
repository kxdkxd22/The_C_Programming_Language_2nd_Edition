#include<stdio.h>

double atof(char *s);

main(){
	char s[1024] = "-123.6781";
	printf("%18.8f\n",atof(s));
	
}


double atof(char *s){

	double val,power;
	int sign;

	for(;isspace(*s);s++)
		;
	sign = (*s == '-')?-1:1;
	if(*s == '+'||*s == '-')
		s++;
	for(val = 0.0; isdigit(*s);s++)
		val = 10.0* val+(*s-'0');
	if(*s == '.')
		s++;
	for(power = 1.0; isdigit(*s);s++){
		val = 10.0*val+(*s-'0');
		power *= 10.0;
	}
	return sign * val/power;
}
