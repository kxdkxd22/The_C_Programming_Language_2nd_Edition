#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASHSIZE 101

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

main(){
	struct nlist *p1,*p2;
	char name[1024] = "MAXLENGHT";	
	char defn[1024] = "1000";
	p1 = install(name,defn);
	
	p2=lookup(name);
	printf("name:%s defn:%s\n",p2->name,p2->defn);

	undef(name);
	p1=lookup(name);
	if(p1==NULL)
		printf("true\n");
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
