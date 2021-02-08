#include<stdio.h>
#define IN 1
#define OUT 0
#define MAXWORDLEN 15

main(){

int c,state,wl,i,j;
state = OUT;
int length[MAXWORDLEN+1];

wl=0;

for(i = 0; i <= MAXWORDLEN; i++){
	length[i] = 0;
}

while((c=getchar())!=EOF){

	if(c==' '|| c == '\n' || c == '\t'){
		if(state == IN){
			if(wl <= MAXWORDLEN){
				length[wl-1]+=1;
			}
			else{
				length[MAXWORDLEN]+=1;	
			}
			state = OUT;
		}

	}else{
		if(state == OUT){
			wl = 0;
			state = IN;
		}	

		wl += 1;
	}

}

printf("horizontal: \n");

for(i = 0; i <= MAXWORDLEN; i++){

	if(i!=MAXWORDLEN){
		printf("%3d: ",i+1);
	}else{
		printf(">%2d: ",MAXWORDLEN);
	}	


	for(j = 0; j < length[i]; j++){
		printf(" * ");
	}

	printf("\n");
}


printf("vertical: \n");

int maxval = 0;

for(i = 0; i < MAXWORDLEN; i++){
	if(length[i]>maxval){
		maxval = length[i];
	}
}

for(i = 0; i < maxval; i++){
	
	printf("%2d |",maxval-i);
	for(j = 0; j <= MAXWORDLEN; j++){
		if(length[j]>=maxval-i){
			printf(" * ");
		}else{
			printf("   ");
		}
	}
	printf("\n");
}

printf("----");

for(i = 0 ; i <= MAXWORDLEN; i++ ){
	printf("---");
}
printf("\n");

printf("   ");
for(i = 0; i<=MAXWORDLEN; i++){
	if(i!=MAXWORDLEN){
		printf("%3d",i+1);
	}
	else{
		printf("%3d>",i);
	}
}
printf("\n");

}
