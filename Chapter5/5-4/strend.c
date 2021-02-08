#include<stdio.h>

int my_strend(char *s,char *t);

main(){
	char s[1024] = "qwertyui";
	char t[1024] = "yui";

	printf("%d\n",my_strend(s,t));

	char s1[1024] = "qweqweqweq";
	char t1[1024] = "xzcxc";

	printf("%d\n",my_strend(s1,t1)); 

}

int my_strend(char *s,char *t){
	
	int ls,lt;
	
	char *bs = s,*bt = t;
	
	for(ls=0;*s!='\0';s++,ls++)
		;
	for(lt=0;*t!='\0';t++,lt++)
		;
	
	s = bs;
	t = bt; 
	
	if(ls>lt){
		s+=ls-lt;
		while(*s!='\0'&&*t!='\0'&&(*s++==*t++))	
				;
		if(*s=='\0'&&*t=='\0')
			return 1;
		
	}

	return 0;
}	
