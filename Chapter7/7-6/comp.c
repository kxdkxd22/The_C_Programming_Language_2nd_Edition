#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 100
int compare(FILE *,FILE *);

main(int argc,char *argv[]){
	FILE *fp1,*fp2;
	char *prog = argv[0];

	if(argc != 3){
		fprintf(stderr,"compare program need two files name\n");
		exit(1);
	}else{
		if((fp1=fopen(*++argv,"r"))==NULL){
			fprintf(stderr,"%s: can't open %s\n",prog,*argv);
			exit(2);
		}else if((fp2=fopen(*++argv,"r"))==NULL){
			fprintf(stderr,"%s: can't open %s\n",prog,*argv);
			exit(3);
		}else{
			compare(fp1,fp2);
			fclose(fp1);
			fclose(fp2);
			exit(0);
		}
		

	}
	
	exit(0);
}

int compare(FILE *fp1,FILE *fp2){
	
	char line1[MAXLEN],line2[MAXLEN];
	char *lp1,*lp2;
	
	do{
		lp1 = fgets(line1,MAXLEN,fp1);
		lp2 = fgets(line2,MAXLEN,fp2);
		
		if(lp1==line1&&lp2==line2){
			if(strcmp(lp1,lp2)!=0){
				printf("%s",lp1);
				printf("%s",lp2);
				exit(0);
			}
			
		}else if(lp1!=line1&&lp2==line2){
			
			fprintf(stderr,"first file come to the end\n");
		}else if(lp1==line1&&lp2!=line2){
			
			fprintf(stderr,"second file come to the end\n");
		}
		
	
	}while(lp1==line1&&lp2==line2);
}





