#include<stdio.h>
#include<ctype.h>

#define MAXWORD 100
#define BUFSIZE 100

int getword(char *word,int lim);
int getch(void);
void ungetch(int);

int buf[BUFSIZE];
int bufp = 0;

main(){
	
	char word[MAXWORD];
	while(getword(word,MAXWORD)!=EOF){
		printf("%s\n",word);
	}
}


int getword(char *word,int lim){

	int c,getch(void);
	void ungetch(int);
	char *w = word;

	while(isspace(c = getch()))
		;
	if(c!=EOF)
		*w++ = c;
	if(isalpha(c)||c=='_'||c=='#'){
		for(;--lim>0;w++)
			if(!isalnum(*w=c=getch())&& *w != '_'){
				ungetch(*w);
				break;	
			}
		*w = '\0';
	}
	
	if(c == '\''){
		*w++ =  getch();
		*w++ =  getch();
		*w = '\0';
		
	}
	
	if(c == '"'){
		for(;--lim>0;w++)
			if((*w=getch())==c){
				*++w = '\0';
				break;
			}	
	}

	if(c == '/')
	{
		*w = getch();
		
		if(*w=='/'){
			for(w++;--lim>0;w++)
				if((*w=getch())=='\n'){
					*++w = '\0';
					return c;	
				}		
		}
		
		if(*w =='*'){
			for(w++;--lim>0;w++){
				if((*w=getch())=='*'){
					if((*++w = getch())=='/'){
						*++w = '\0';
						return c;
					}	
				}		
			}
		}
		ungetch(*w);
	}
		
	return c;
}

int getch(void){
	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c){
	if(bufp>=BUFSIZE)
		printf("erro: too many characters\n");
	else
		buf[bufp++]=c;
}

