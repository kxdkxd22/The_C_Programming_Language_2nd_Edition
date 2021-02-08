#include<stdio.h>
#include<ctype.h>

#define NUMBER '0'

int getop(char s[]);

main(){
	char s[1024];
	while(getop(s)!=EOF){
		printf("%s ",s);
	}

}


int getop(char s[]){

	int i,c,rc;
	
	static char lastc[] = " ";
	
	sscanf(lastc,"%c",&c);	
	lastc[0] = ' ';	
	while((s[0]=c)==' '|| c == '\t')
		if(scanf("%c",&c)==EOF)
			c = EOF;
	s[1] = '\0';
	
	if(!isdigit(c)&&c!='.')
		return c;
	
	i = 0;
	if(isdigit(c))
		do{
			rc = scanf("%c",&c);
			if(!isdigit(s[++i] = c)){
				break;
			}
		}while(rc!=EOF);	

	
	if(c=='.')
		do{
			rc = scanf("%c",&c);
			if(!isdigit(s[++i]=c))
				break;
		}while(rc!=EOF);
	s[i] = '\0';
	if(c!=EOF)
		lastc[0] = c;
	return NUMBER;
}



