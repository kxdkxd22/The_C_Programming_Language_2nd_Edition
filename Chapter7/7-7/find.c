#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 1000
void fpat(FILE *,char *,char *,int,int);

main(int argc,char *argv[]){

	char line[MAXLINE];
	char pattern[MAXLINE];
	long lineno = 0;
	int c,except = 0,number = 0,found = 0;
	FILE *fp;

	while(--argc>0&&(*++argv)[0] == '-')
		while(c = *++argv[0])
			switch(c){
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				fprintf(stderr,"find: illegal option %c\n",c);
				argc = 0;
				found = -1;
				break;
			}
		
	if(argc>=1){
		strcpy(pattern,*argv);
	}else{
		fprintf(stderr,"find -x -n pattern\n");
		exit(1);
	}

	if(argc == 1){
		fpat(stdin,"",pattern,except,number);			
	}else{
		if((fp=fopen(*++argv,"r"))==NULL){
			fprintf(stderr,"can't open%s\n",*argv);
			exit(2);
		}else{
			fpat(fp,*argv,pattern,except,number);
			fclose(fp);
		}
			
	}

}


void fpat(FILE *fp,char *filename,char *pattern,int except,int number){
	
	char line[MAXLINE];
	int lineno = 0,found = 0;
	
	while(fgets(line,MAXLINE,fp)!=NULL){
		lineno++;
		if((strstr(line,pattern)!=NULL)!=except){
			if(*filename)
				printf("filename:%s - ",filename);
			if(number)
				printf("linenum:%d ",lineno);
			printf("%s",line);
			found++;
		}
		
	}	
	
}




