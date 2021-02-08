#include<stdio.h>

#define my_issupper(c) ((c)>='A'&&(c)<='Z')?1:0
int f_issupper(char);

main(){

	char c = 'X';
	
	printf("%d\n",f_issupper(c));
	printf("%d\n",my_issupper(c)); 

}

int f_issupper(char c){

	if(c>='A'&&c<='Z')
		return 1;
	else
		return 0;

}
