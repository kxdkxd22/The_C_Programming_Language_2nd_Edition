#include<stdio.h>


void sequeeze(char s1[],char s2[]);

main(){

	char s1[1024],s2[1024];
	int i,c;
	
	for(i = 0; (c=getchar())!='\n'; i++){
		s1[i] = c;
	}
	s1[i] = '\0';

	for(i = 0; (c=getchar())!='\n'; i++){
		s2[i] = c;
	}
	s2[i] = '\0';

	sequeeze(s1,s2);
	printf("%s\n",s1);
	
}

void sequeeze(char s1[],char s2[]){
	
	int i,j,k=0;
	int in;
	for(i = 0; s1[i]!='\0'; i++){
		in = 1;
		for(j = 0; s2[j]!='\0'; j++){
			if(s1[i] == s2[j]){
				in = 0;
				break;
			}
		}
		if(in){
			s1[k++] = s1[i];
		}
	}
	
	s1[k] = '\0';
}


