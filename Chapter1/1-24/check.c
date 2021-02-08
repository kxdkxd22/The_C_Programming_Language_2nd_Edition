#include<stdio.h>

int brace,brack,paren;
void in_comment();
void search(int c);

main(){
	
	int c,d;
	extern int brace,brack,paren;
	
	while((c=getchar())!=EOF){
		if(c == '/'){
			if((d=getchar())=='*'){
				in_comment();
			}else{
				search(c);
			}
		}else{
			search(c);
		}	
		
		if(brace<0){
			printf("unblanced brace error!\n");
		}
		if(brack<0){
			printf("unblanced brack error!\n");
		}
		if(paren<0){
			printf("unblanced paren error!\n");
		}
	}
	
	if(brace>0){
		printf("unblanced brace error!\n");
	}
	if(brack>0){
		printf("unblanced brack error!\n");
	}
	if(paren>0){
		printf("unblanced paren error!\n");
	}

}

void in_comment(){
	int c,d;
	
	c = getchar();
	d = getchar();
	
	while(c!='*' || d!='/'){
		c = d;
		d = getchar();
	} 

}

void search(int c){

	if(c == '{'){
		brace++;
	}else if(c == '}'){
		brace--;
	}else if(c == '['){
		brack++;
	}else if(c == ']'){
		brack--;
	}else if(c == '('){
		paren++;
	}else if(c == ')'){
		paren--;
	}

}
