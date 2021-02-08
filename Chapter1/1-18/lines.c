#include<stdio.h>
#define MAXLINE 1000

int get_line(char line[],int maxline);
int remove_bt(char line[]);

main(){

	
	char line[MAXLINE];

	while(get_line(line,MAXLINE)>0){
		if(remove_bt(line)>0){
			printf("%s\n",line);
		}
	}

}

int get_line(char s[],int lim){

	int c,i;
	
	for(i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
		s[i] = c;
	}

	if(c == '\n'){
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

int remove_bt(char line[]){

	int i;

	while(line[i]!='\n'){
		++i;
	}

	--i;
	while(i>=0 && (line[i]==' '|| line[i] == '\t')){
		--i;
	}
	
	if(i >= 0){
		++i;
		line[i] = '\n';
		++i;
		line[i] = '\0'; 
	}
	
	return i;
}









