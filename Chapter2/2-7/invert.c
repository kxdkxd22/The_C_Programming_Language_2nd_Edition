#include<stdio.h>

unsigned invert(unsigned x,int p,int n);

main(){

	unsigned result;
		
	result = invert(170,4,3);
	printf("%u\n",result);	

}

unsigned invert(unsigned x,int p,int n){
	unsigned result;
	
	result =(((~(~0<<n))<<(p-n+1))^x);

	return result;
}
