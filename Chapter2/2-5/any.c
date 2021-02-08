#include<stdio.h>

int any(char s1[],char s2[]);

main(){
	
	char s1[1024],s2[1024];
        int i,c;

        for(i = 0; (c=getchar())!='\n'; i++){
                s1[i] = c;
        }
        s1[i] = '\0';

        for(i = 0; (c=getchar())!='\n'; i++){
                s2[i] = c;
        }
        s2[i] = '\0';

        printf("%d\n",any(s1,s2));
	
}


int any(char s1[],char s2[]){
	
	int i,j;
	int in;

	for(i = 0; s2[i]!='\0'; i++){
		for(j = 0; s1[j]!='\0'; j++){
			if(s2[i]==s1[j]){
				return j;
			}
		}
		
	}	
	return -1;
}









