#include<stdio.h>

#define swap(t,x,y) {t z = x; x = y; y = z;}

main(){
	int xx = 3, yy = 4;
	swap(int,xx,yy);

	printf("%d\n",xx);
	printf("%d\n",yy);

}
