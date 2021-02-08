#include<stdio.h>
#include<string.h>

void reverse(char s[]);

main(){

	char s[1024] = "abcdef";

	reverse(s);
	printf("%s\n",s);

}

void reverse(char s[]){


	void reverser(char s[],int i,int len);

	reverser(s,0,strlen(s));
}

void reverser(char s[],int i,int len){

	int j,c;
		
	j = len-(i+1);

	if(i<j){
		c = s[i];
		s[i] = s[j];
		s[j] = c;	
		reverser(s,++i,len);
	}

}



