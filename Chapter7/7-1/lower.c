#include<stdio.h>
#include<ctype.h>

main(int argc,char * argv[]){
	int c;
	
	if(strcmp(argv[0],"tolower")==0){
		while((c=getchar())!=EOF)
			putchar(tolower(c));
	}else{
		while((c=getchar())!=EOF)
                        putchar(toupper(c));
	}
		

}
