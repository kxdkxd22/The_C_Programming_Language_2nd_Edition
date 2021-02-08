#include<stdio.h>
#include<string.h>


main(){

	char s1[1024] = "qwer1234";
	char s2[1024] = "dasdqwer1234\n";

	printf("s1-length:%d,s2-length%d\n",strlen(s1),strlen(s2));
	
	printf("%d\n",strcmp(s1,s2));

	printf("%s\n",strstr(s2,s1));
}
