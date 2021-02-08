#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASHSIZE 101
#define MAXWORD 100
#define BUFSIZE 100

struct nlist{
	struct nlist *next;
	char *name;
	char *defn;
};

static struct nlist *hashtab[HASHSIZE];
unsigned hash(char *s);
struct nlist *lookup(char *);
char *my_strdup(char *);
struct nlist *install(char *,char *);
void undef(char *s);
int getword(char *,int);
void getdef(void);

int buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);

main(){
	struct nlist *p,*p2;
	
	char w[MAXWORD];	
	
	while(getword(w,MAXWORD)!=EOF)
		if(strcmp(w,"#")==0)
			getdef();
		else
			printf("%s",w);


	char name[1024] = "IN";
	p2=lookup(name);

	if(p2==NULL)
		printf("true\n");
	else
		printf("name:%s defn:%s\n",p2->name,p2->defn);

}

int getword(char *word,int lim){

	int c,getch(void);
        void ungetch(int);
        char *w = word;

        while((c = getch())==' '||c=='\t')
                ;
        if(c!=EOF)
                *w++ = c;

        if(!isalpha(c)&&c!='_'){
                *w = '\0';
                return c;
        }
        for(;--lim>0;w++)
                 if(!isalnum(*w=getch())&& *w != '_'){
                         ungetch(*w);
                         break;
        }
       *w = '\0';
       return c;

}

void getdef(void){
	int c,i;
	char def[MAXWORD],dir[MAXWORD],name[MAXWORD];

	if(!isalpha(getword(dir,MAXWORD)))
		printf("getdef: expecting define string\n");
	else if(strcmp(dir,"define")==0)
		if(!isalpha(getword(name,MAXWORD)))
			printf("getdef: expecting name string\n");
		else{
			for(i = 0; i < MAXWORD; i++)
				if((def[i] = getch())==EOF||def[i] == '\n')
					break;
			
			def[i] = '\0';
			if(i<=0)
				printf("getdef: expecting def string\n");
			else
				install(name,def);
		}
	else if(strcmp(dir,"undef")==0)
		if(!isalpha(getword(name,MAXWORD)))
			printf("getdef: expecting a undef string\n");
		else
			undef(name);

}

void undef(char *s){
	int h;
	
	struct nlist *np,*prev=NULL;
	h = hash(s);
	for(np=hashtab[h];np!=NULL;np=np->next){
		if(strcmp(s,np->name)==0)
			break;
		prev = np;
	}
	
	if(np!=NULL){
		if(prev == NULL)
			hashtab[h] = np->next;
		else
			prev->next = np->next;
		free((void *)np->name);
		free((void *)np->defn);
		free((void *)np);
	}

}

unsigned hash(char *s){
	unsigned hashval;
	
	for(hashval = 0; *s != '\0'; s++)
		hashval = *s + 31*hashval;
	return hashval % HASHSIZE;

}

struct nlist *lookup(char *s){
	struct nlist *np;

	for(np = hashtab[hash(s)];np != NULL; np = np->next)
		if(strcmp(s,np->name)==0)
			return np;
	return NULL;	

}

struct nlist *install(char *name,char *defn){
	struct nlist *np;
	unsigned hashval;
	
	if((np=lookup(name)) == NULL){
		np = (struct nlist *)malloc(sizeof(*np));
		if(np == NULL||(np->name = my_strdup(name))==NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}else
		free((void *)np->defn);

	if((np->defn=my_strdup(defn))==NULL)
		return NULL;
	return np;
}

char *my_strdup(char *s){
	char *p;

	p = (char *)malloc(strlen(s)+1);
	if(p!=NULL)
		strcpy(p,s);
	return p;
}

int getch(void){
	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c){
	if(bufp>=BUFSIZE)
		printf("error: too many characters\n");
	else
		buf[bufp++] = c;
}

