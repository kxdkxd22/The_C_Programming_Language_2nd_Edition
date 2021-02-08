#include<stdio.h>
#include<stdlib.h>

#define MAXHDR 5
#define MAXBOT 3
#define MAXLINE 100
#define MAXPAGE 10

void fileprint(FILE *fp,char *fname);
int heading(char *,int);

main(int argc,char *argv[]){
	FILE *fp;
	
	if(argc == 1){
		fileprint(stdin," ");
	}else{
		while(--argc>0){
			if((fp = fopen(*++argv,"r"))==NULL){
				fprintf(stderr,"can't open %s\n",*argv);
				exit(1);
			}else{
				fileprint(fp,*argv);
				fclose(fp);
			}
		}

	}
	
}

void fileprint(FILE *fp,char *fname){
	int lineno,pageno = 1;

	char line[MAXLINE];
	
	lineno = heading(fname,pageno++);
	
	while(fgets(line,MAXLINE,fp)!=NULL){
		if(lineno==1){
			fprintf(stdout,"\f");
			lineno = heading(fname,pageno++);	
		}	
		
		fputs(line,stdout);
		if(++lineno>MAXPAGE-MAXBOT)
			lineno = 1;
	}
	
}

int heading(char * fname,int pageno){
	
	int ln = 3;
	fprintf(stdout,"\n\n");
	fprintf(stdout,"filename: %s pagenumber: %d \n",fname,pageno);
	while(ln++<MAXHDR){
		fprintf(stdout,"\n");
	}
	return ln;
	
}

