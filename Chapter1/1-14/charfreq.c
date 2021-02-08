#include<stdio.h>
#define NUMCHARS 128

main(){

int c,charArray[NUMCHARS],i;

for(i = 0; i < NUMCHARS; i++){
	charArray[i] = 0;
}

while((c=getchar())!=EOF){
	charArray[c] +=1; 
}

for(c = 0; c < NUMCHARS; c++){
 
	if(charArray[c]>0){
		if(c == '\n'){
			printf("\\n");
		}else if(c == '\b'){
			printf("\\b");
		}else if(c == '\t'){
			printf("\\t");
		}else{
		//	printf("%2c",c);
		}
		
		printf("(%c) : %2d\n",c,charArray[c]);
	}

}

}
