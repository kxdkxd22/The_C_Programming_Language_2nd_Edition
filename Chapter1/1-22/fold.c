#include<stdio.h>
#define MAXCOL 10
#define TABWIDTH 8

char line[MAXCOL];

void printl(int pos);
int newpos(int pos);
int findblanks(int pos);
int exptab(int pos);

main(){

	int c,pos;
	pos = 0;

	while ((c=getchar())!=EOF){
		line[pos] = c;
		if(c == '\n'){
			printl(pos);
			pos = 0;
		}else if(c == '\t'){
			pos = exptab(pos);		
		}else if(++pos >= MAXCOL){
			pos = findblanks(pos);
			printl(pos);
			pos = newpos(pos);	
		}
	}	
}

void printl(int pos){
	int i;
	for(i = 0; i < pos; i++){
		putchar(line[i]);
	}
	
	if(pos>0){
		putchar('\n');
	}
}

int exptab(int pos){
	line[pos] = ' ';
	for(++pos; pos < MAXCOL && (pos%TABWIDTH)!=0; ++pos){
		line[pos] = ' ';
	}

	if(pos < MAXCOL){
		return pos;
	}else{
		printl(pos);
		return 0;
	}
}

int findblanks(pos){
	int i;
	for(i = pos-1; i>=0 ;--i){
		if(line[i] == ' '){
			break;
		}
	}
	
	if(i <= 0 || i == pos-1){
		return pos;
	}else{
		pos = i+1;
		return pos;
	}
}

int newpos(int pos){
	int i,j;
	
	for(i=0;pos < MAXCOL;pos++,i++){
		line[i]	= line[pos];
	}	
	
	return i;
}









