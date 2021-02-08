#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100

struct tnode{
	char *word;
	int match;
	struct tnode *left;
	struct tnode *right;
};

enum{NO,YES};

struct tnode *talloc(void);
char * my_strdup(char *);

struct tnode *addtree(struct tnode *,char *,int,int *);
void treeprint(struct tnode *);
int compare(char *,struct tnode *,int,int*);

int getword(char *word,int lim);
int getch(void);
void ungetch(int);

int buf[BUFSIZE];
int bufp = 0;

main(int argc,char *argv[]){
	
	struct tnode *root;
	char word[MAXWORD];
	int found  = NO;
	int num = (--argc>0&&(*++argv)[0]=='-')?atoi(argv[0]+1):6;
		
	root = NULL;
	while(getword(word,MAXWORD)!=EOF){
		if(isalpha(word[0])&&strlen(word)>=num)
			root = addtree(root,word,num,&found);
		found = NO;
	}
	printf("hello world \n");
	treeprint(root);
}

struct tnode *addtree(struct tnode *p,char *w,int num,int *found){
	int cond;

	if(p==NULL){
		p = talloc();
		p->word = my_strdup(w);
		p->match = *found;
		p->left= p->right = NULL;
	}else if((cond=compare(w,p,num,found))<0){
		p->left = addtree(p->left,w,num,found);
	}else if(cond > 0){
		p->right = addtree(p->right,w,num,found);
	}
	
	return p;	
}

int compare(char *s,struct tnode *p,int num,int *found){
	int i;
	char *t = p->word; 
	for(i=0;*s==*t;s++,t++,i++){
		if(*s=='\0'&&*t=='\0')
			return 0;
	}
	if(i>=num){
		*found =YES;
		p->match = YES;
	}
	
	return *s-*t;
}

void treeprint(struct tnode *p){
	if(p!=NULL){
		treeprint(p->left);
		if(p->match)
			printf("%s\n",p->word);
		treeprint(p->right);
	}
	
}

struct tnode *talloc(void){

	return (struct tnode *)malloc(sizeof(struct tnode));
}

char *my_strdup(char *s){
	
	char *p;
	p = (char *)malloc(strlen(s)+1);
	if(p!=NULL)
		strcpy(p,s);
	return p;
}

int getword(char *word,int lim){

	int c,getch(void);
	void ungetch(int);
	char *w = word;

	while(isspace(c = getch()))
		;
	if(c!=EOF)
		*w++ = c;

	if(!isalpha(c)&&c!='_'&&c!='#'){
		*w = '\0';
		return c;
	}
        for(;--lim>0;w++)
                 if(!isalnum(*w=c=getch())&& *w != '_'){
                         ungetch(*w);
                         break;
        }
       *w = '\0';		
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

