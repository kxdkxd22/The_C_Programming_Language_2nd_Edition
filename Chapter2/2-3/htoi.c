#include<stdio.h>

main(){

	int i,c;
	char  s[1024];

	for(i=0;(c=getchar())!=EOF;i++){
		s[i] = c;
	}
	s[i] = '\0';
	
	printf("%d\n",htoi(s));

}

int htoi(char s[]){
	
	int i,n;
	i = 0;
	n=0;

	if(s[i]=='0'){
		++i;
		if(s[i]=='x'||s[i]=='X'){
			++i;
		}
	}
	
	for(;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){

			n = 16*n+(s[i]-'0');
		}else if(s[i]>='a'&&s[i]<='z'){
	
			n = 16*n + 10+s[i]-'a';
		}else if(s[i]>='A'&&s[i]<='Z'){
			
			n = 16*n+ 10 + s[i]-'A';
		}		
	}

	return n;
	
}

