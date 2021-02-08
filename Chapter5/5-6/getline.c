#include<stdio.h>
#define MAXLINE 1000

int my_getline(char *s,int lim);

main(){
	char line[MAXLINE];
	while(my_getline(line,MAXLINE)){

		printf("%s",line);
	}	

}


int my_getline(char *s,int lim){

	int c,i;
	i = 0;
	while(--lim>0&&(c=getchar())!=EOF&&c!='\n'){
		*s++ = c;
		i++;	
	}
	if(c == '\n'){
		*s++ = c;
		i++;
	}
	*s = '\0';
	return i;
}

