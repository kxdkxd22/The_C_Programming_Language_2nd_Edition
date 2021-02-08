#include<stdio.h>
#include"fcntl.h"
#include<stdarg.h>
#include<stdlib.h>

void error(char *fmt,...);

void filecopy(int ifp,int ofp);

main(int argc,char *argv[]){
	
	int f1,n;
	
	if(argc==1){
		filecopy(0,1);
	}else{
		if((f1=open(argv[1],O_RDONLY,0))==-1)
			error("cp: can't open %s",argv[1]);
		filecopy(f1,1);
		close(f1);
	}


}


void filecopy(int ifp,int ofp){
	int n;
	char buf[BUFSIZ];
	while((n=read(ifp,buf,BUFSIZ))>0)
		if(write(ofp,buf,n)!=n)
			error("cp: write error on file");
}


void error(char *fmt,...){
	va_list args;
	
	va_start(args,fmt);
	fprintf(stderr,"error: ");
	vfprintf(stderr,fmt,args);
	fprintf(stderr,"\n");
	va_end(args);
	exit(1);
}











