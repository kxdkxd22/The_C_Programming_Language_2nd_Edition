#include<stdio.h>
#include<stdlib.h>

void *my_calloc(unsigned n,unsigned size);

main(){
	
	char * s=my_calloc(2,5);
	int i;
	for(i=0;i<10;i++,s++)
		printf("%d\n",*s);
}

void *my_calloc(unsigned n,unsigned size){

	unsigned i,nb;
	nb = n*size;
		
	char *p,*q;
	if((p=q=malloc(nb))!=NULL)
		for(i=0;i<nb;i++)
			*p++=0;
	return q;
}
