#include<stdio.h>
#include<string.h>

#define BUFSIZE 100
int buf[BUFSIZE];
int bufp = 0;
int getch(void);
void ungetch(int c);

#define MAXTOKEN 100

enum{NAME,PARENS,BRACKETS};

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int gettoken(void);
void dirdcl(void);
void dcl(void);

enum{NO,YES};
int prevtoken=NO;

void parmdcl(void);
void dclspec(void);
int typespec(void);
int typequal(void);
int compare(char **,char **);

main(){

	while(gettoken()!=EOF){
		strcpy(datatype,token);
		out[0] = '\0';
		dcl();
		if(tokentype !='\n')
			printf("syntax error\n");
		printf("%s: %s %s\n",name,out,datatype);		
	}

	return 0;
}

int gettoken(void){
	int c,getch(void);
	void ungetch(int);
	char *p = token;
	if(prevtoken == YES){
		prevtoken = NO;
		return tokentype;
	}
	while((c=getch())==' '||c == '\t')
		;
	if(c=='('){
		if((c=getch())==')'){
			strcpy(token,"()");
			return tokentype = PARENS;
		}else{
			ungetch(c);
			return tokentype = '(';
		}
	}else if(c == '['){
		for(*p++ = c;(*p++=getch())!=']';)
			;
		*p = '\0';
		return tokentype = BRACKETS;
	}else if(isalpha(c)){
		for(*p++=c;isalnum(c=getch());)
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	}else
		return tokentype = c;

}

void dcl(void){
	int ns;
	
	for(ns = 0; gettoken() == '*';)
		ns++;
	if(tokentype == ',')
		prevtoken = YES;
	dirdcl();             
	if(tokentype==NAME&&typespec() == NO&&typequal() == NO){
		prevtoken = NO;
                gettoken();
        }

	while(ns-->0)
		strcat(out," pointer to");
}

void dirdcl(void){
	int type;
	
	if(tokentype == '('){
		dcl();
		if(tokentype!=')')
			printf("error: missing )\n");
	}else if(tokentype == NAME)
		if(name[0]=='\0')
			strcpy(name,token);
		
	else
		prevtoken = YES;
	
	while((type=gettoken())==PARENS||type == BRACKETS||type == '(')
		if(type == PARENS)
			strcat(out," function returning");
		else if(type == '('){
			strcat(out," function expecting");
			parmdcl();
			strcat(out," and returning");
		}		
		else{
			strcat(out," array");
			strcat(out,token);
			strcat(out," of");
		}
	
}

void parmdcl(void){

	do{
		dclspec();
	}while(tokentype == ',');
	if(tokentype!=')')
		printf("missing ) in parameter declaration\n");

}

void dclspec(void){

	char temp[MAXTOKEN];

	temp[0] = '\0';
	gettoken();

	do{
		if(tokentype!=NAME){
			prevtoken = YES;
			dcl();
		}else if(typespec() == YES){
			strcat(temp," ");
			strcat(temp,token);
			gettoken();
		}else if(typequal() == YES){
			strcat(temp," ");
			strcat(temp,token);
			gettoken();
		}else
			printf("unknown type in parameter list\n");
	
	}while(tokentype!=','&& tokentype!=')');
	strcat(out,temp);
	if(tokentype == ',')
		strcat(out,",");
}


int typespec(void){
	
	static char *types[]={"char","int","void"};
	char *pt = token;
	
	if(bsearch(&pt,types,sizeof(types)/sizeof(char *),sizeof(char *),compare)==0)
		return NO;
	else
		return YES;
}


int typequal(void){

        static char *typeq[]={"const","volatile"};
        char *pt = token;

        if(bsearch(&pt,typeq,sizeof(typeq)/sizeof(char *),sizeof(char *),compare)==0)
                return NO;
        else
                return YES;
}


int compare(char **s,char **t){
	return strcmp(*s,*t);
}

int getch(void){
	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c){
	if(bufp>=BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

