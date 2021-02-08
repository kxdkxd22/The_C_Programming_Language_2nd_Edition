#include<stdio.h>
#include<ctype.h>

double my_atof(char s[]);

main(){
	
	char s1[1024]="123.45e-6",s2[1024]="23.45";
	
	printf("%10.10f\n",my_atof(s1));


	printf("%10.10f\n",my_atof(s2));
}


double my_atof(char s[]){

	double val,power;
	
	int i,sign,exp;
	
	for(i = 0; isspace(s[i]);i++)
		;

	sign = (s[i]=='-')?-1:1;
	if(s[i]=='+'||s[i]=='-')
		i++;

	for(val = 0.0; isdigit(s[i]);i++)
		val = 10.0*val+(s[i]-'0');

	if(s[i] == '.')
		i++;

	for(power = 1.0; isdigit(s[i]); i++){
		val = 10.0*val + (s[i]-'0');
		power*=10.0;
	}

	val = sign *val /power;

	if(s[i] == 'e'){
		sign = (s[++i]=='-')?-1:1;
		
		if(s[i] == '+' || s[i] == '-'){
			i++;
		}
		
		for(exp=0; isdigit(s[i]);i++){
			exp = 10.0*exp+(s[i]-'0');
		}

		if(sign>0){
			while(exp-->0)
				val*=10.0;

		}else{
			while(exp-->0)
				val/=10.0;
		}
	}
	
	return val;	
}
