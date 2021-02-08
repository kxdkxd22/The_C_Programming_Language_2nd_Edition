#include<stdio.h>
#define MAXLINE 1000

int my_getline(char line[],int max);
int strrindex(char source[],char searchfor[]);

char pattern[] = "qwer";

main(){
	char line[MAXLINE];
	int found = 0;

	while(my_getline(line,MAXLINE)){
		if(strrindex(line,pattern)>=0){
			printf("%s : position: %d",line,strrindex(line,pattern));
			found++;
		}
	
	}
	return found;
	
}

int my_getline(char s[],int lim){
	
	int i = 0;
	char c;

	while(--lim&&(c=getchar())!=EOF&&c!='\n'){
		s[i++] = c;
	}

	if(c == '\n'){
		s[i++] = c;
	}

	s[i] = '\0';
	return i;

}

int strrindex(char s[],char t[]){
	int i,j,k;
	
	int result = -1;
	for(i=0;s[i]!='\0';i++){
		for(j=i,k=0;t[k]!='\0'&&s[j]==t[k];j++,k++){
		
		}
		if(k>0&&t[k]=='\0'){
			result = i;
		}
	
	}
	
	return result;
}
