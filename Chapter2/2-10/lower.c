#include<stdio.h>

char lower(char c);

main(){

	printf("%c\n",lower('A'));

}

char lower(char c){

	return c>='A'&&c<='Z'?c+32:c;

}
