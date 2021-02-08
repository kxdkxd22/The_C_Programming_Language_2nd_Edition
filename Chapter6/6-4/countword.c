#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100
#define TNODENUM 100

struct tnode{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *talloc(void);
char * my_strdup(char *);

struct tnode *addtree(struct tnode *,char *);
void treestore(struct tnode *);
void sortlist();

int getword(char *word,int lim);
int getch(void);
void ungetch(int);

int buf[BUFSIZE];
int bufp = 0;

struct tnode* list[TNODENUM];
int ntn = 0;

main(int argc,char *argv[]){
	
	struct tnode *root;
	char word[MAXWORD];
	int c,i;
		
	root = NULL;
	while((c=getword(word,MAXWORD))!=EOF){
		if(isalpha(word[0]))
			root = addtree(root,word);
	}

	treestore(root);
	sortlist();
	
	for(i = 0; i <ntn;i++)
		printf("%2d:%20s\n",list[i]->count,list[i]->word);
}


struct tnode *addtree(struct tnode *p,char *w){
	int cond;

	if(p==NULL){
		p = talloc();
		p->count = 1;
		p->word = my_strdup(w);
		p->left= p->right = NULL;
	}else if((cond=strcmp(w,p->word))<0){
		p->left = addtree(p->left,w);
	}else if(cond > 0){
		p->right = addtree(p->right,w);
	}else if(cond == 0)
		p->count++;

	return p;	
}


void treestore(struct tnode *p){
	struct linklist *temp;
	if(p!=NULL){
		treestore(p->left);
		if(ntn<TNODENUM)
			list[ntn++] = p;
		treestore(p->right);
	}
	
}

void sortlist(){
	
	int gap,i,j;
	struct tnode *temp;

	for(gap = ntn/2; gap > 0; gap/=2)
		for(i = gap;i < ntn; i++)
			for(j = i-gap; j >= 0; j-=gap){
				if(list[j]->count>list[j+gap]->count)
					break;
				temp = list[j];
				list[j] = list[j+gap];
				list[j+gap] = temp;

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

