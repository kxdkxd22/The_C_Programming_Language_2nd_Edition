#include<stdio.h>
#define LIMIT 10

main(){

	int i,lim,c;
	lim = LIMIT;
	i = 0;
	char s[LIMIT];
	while(i<lim){
		c = getchar();
		if(c == EOF){
			break;
		}
		
		if(c == '\n'){
			break;
		}
		s[i++] = c;
	}
	
	s[i] = '\0';
	printf("%s\n",s);
}
