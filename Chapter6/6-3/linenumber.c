#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100

struct linklist{
	int lnum;
	struct linklist *ptr;
};

struct tnode{
	char *word;
	struct linklist *lines;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *talloc(void);
char * my_strdup(char *);

struct linklist *lalloc(void);
struct tnode *addtree(struct tnode *,char *,int);
void treeprint(struct tnode *);
void addline(struct tnode *,int);

int getword(char *word,int lim);
int getch(void);
void ungetch(int);

int buf[BUFSIZE];
int bufp = 0;

main(int argc,char *argv[]){
	
	struct tnode *root;
	char word[MAXWORD];
	int c,linenumber = 0;
		
	root = NULL;
	while((c=getword(word,MAXWORD))!=EOF){
		if(isalpha(word[0])&&noiseword(word)==-1)
			root = addtree(root,word,linenumber);
		else if(c=='\n')
			linenumber++;
		
	}

	treeprint(root);
}

int noiseword(char *w){
	static char * nw[]={"a","an","and","are","in","is","of","or","that","the","this","to"};
	int low = 0;
	int high = sizeof(nw)/sizeof(char *)-1;
	int mid;
	int cond;

	while(low<=high){
		mid = (low+high)/2;
		if((cond=strcmp(w,nw[mid]))==0)
			return mid;
		else if(cond>0)
			low = mid+1;
		else
			high = mid-1;
	}
	
	return -1;
}

struct tnode *addtree(struct tnode *p,char *w,int linenum){
	int cond;

	if(p==NULL){
		p = talloc();
		p->lines = lalloc();
		p->lines->lnum = linenum;
		p->lines->ptr = NULL;
		p->word = my_strdup(w);
		p->left= p->right = NULL;
	}else if((cond=strcmp(w,p->word))<0){
		p->left = addtree(p->left,w,linenum);
	}else if(cond > 0){
		p->right = addtree(p->right,w,linenum);
	}else if(cond == 0)
		addline(p,linenum);

	return p;	
}

void addline(struct tnode *p,int linenum){
	struct linklist *temp;
	
	temp = p->lines;
	while(temp->ptr!=NULL&&temp->lnum!=linenum)
		temp = temp->ptr;
	if(temp->lnum!=linenum){
		temp->ptr = lalloc();
		temp->ptr->lnum = linenum;
		temp->ptr->ptr =NULL;
	}
		
	
}


struct linklist *lalloc(void){

        return (struct linklist *)malloc(sizeof(struct linklist));
}


void treeprint(struct tnode *p){
	struct linklist *temp;
	if(p!=NULL){
		treeprint(p->left);
		printf("%s: ",p->word);;	
		for(temp=p->lines;temp!=NULL;temp=temp->ptr)
			printf("%4d ",temp->lnum);
		printf("\n");
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

	while((c = getch())==' '||c=='\t')
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

