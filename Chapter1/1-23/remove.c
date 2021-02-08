#include<stdio.h>

void rcomment(char c);
void in_comment1();
void in_comment2();

main(){
	int c;
	while((c=getchar())!=EOF){
		rcomment(c);		
	}

}

void rcomment(char c){
	int d;
	
	if(c == '/'){
		if((d=getchar())=='*'){
			in_comment1();
		}
		else if(d=='/'){
			in_comment2();
		}
		else{
			putchar(c);
			putchar(d);
		}
	
	}else{
		putchar(c);
	}

}


void in_comment1(){
	int c,d;
	c = getchar();
	d = getchar();
	while(c!='*'||d!='/'){
		c = d;
		d = getchar();
	}
}

void in_comment2(){
	int c;
	c=getchar();
	while(c!='\n'){
		c = getchar();
	}
}
