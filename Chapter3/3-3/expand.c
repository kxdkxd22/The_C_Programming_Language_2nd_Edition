#include<stdio.h>

void expand(char s1[],char s2[]);

main(){

	int i;
	char s1[1024],s2[1024];
	char c;
	
	for(i = 0; (c=getchar())!='\n' && i<1024; i++){
		s1[i] = c;
	}
	s1[i] = '\0';
	
	expand(s1,s2);
	
	printf("%s\n",s2);

}


void expand(char s1[],char s2[]){
	
	char c;
	int i=0,j=0;
	
	while((c=s1[i++])!='\0'){
		if(s1[i]=='-'&&s1[i+1]>=c){
			++i;
			while(c<s1[i]){
				s2[j++] = c++;
			}
		}else{

			s2[j++] = c;
		}	

	}
	s2[j] = '\0';

}
