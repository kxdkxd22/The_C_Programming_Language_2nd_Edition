#include<stdio.h>

unsigned setbits(unsigned x,unsigned int p,unsigned int n,unsigned y);

main(){

	unsigned int result;
	
	result = setbits(170,4,3,5);
	printf("%u\n",result);
}


unsigned setbits(unsigned x,unsigned int p,unsigned int n,unsigned y){
	unsigned  result;

	result = (((~(~0<<n))&y)<<(p-n+1))|((~((~(~0<<n))<<(p-n+1)))&x);
	return result;	

}
