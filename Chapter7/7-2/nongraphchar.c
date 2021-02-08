#include<stdio.h>
#include<ctype.h>

#define POSITION 100
#define SIZE 6

int inc(int,int);

main(){
	int c,pos;
	pos = 0;

	while((c=getchar())!=EOF){
		if(iscntrl(c)||c == ' '){
			
			pos = inc(pos,SIZE);
			printf(" \\%0.3o ",c);
			
			if(c == '\n'){
				putchar(c);
				pos = 0;
			}
		}else{
			pos = inc(pos,1);
			putchar(c);
		}
		
	}


}

int inc(int pos,int n){
	
	if(pos+n<POSITION){
		return pos+n;
	}else{
		putchar('\n');
		return n;	
	}
}
