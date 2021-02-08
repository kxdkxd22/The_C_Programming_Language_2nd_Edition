#include<stdio.h>

main(){

int c,d;

while((c=getchar())!=EOF){

if(c == ' '){
while((d=getchar()) == ' ');
putchar(' ');
putchar(d);
}
if(c!=' '){
putchar(c);
}

}

}

