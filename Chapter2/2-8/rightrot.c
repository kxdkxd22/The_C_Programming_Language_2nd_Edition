#include<stdio.h>

unsigned rightrot(unsigned x,int n);

main(){

	printf("%u\n",rightrot(3,1));

}

unsigned rightrot(unsigned x,int n){
	int i;
	for(i = n; i >0; i--)
	if(x&1){
		x = (x>>1)|(~(~0U>>1));
	}else{
		x>>1;
	}
	
	return x;
}

