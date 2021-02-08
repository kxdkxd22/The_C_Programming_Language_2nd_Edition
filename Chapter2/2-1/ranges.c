#include<stdio.h>
#include<limits.h>


main(){
	
	//signed types
	
	printf("signed char maximum values: %d\n",SCHAR_MAX);
	printf("signed char minimum vlaues: %d\n",SCHAR_MIN);

	printf("signed short int maximum values: %d\n",SHRT_MAX);
	printf("signed short int minimum values: %d\n",SHRT_MIN);

	printf("signed int maximum values: %d\n",INT_MAX);
	printf("signed int minimum values: %d\n",INT_MIN);

	printf("signed long int maximum values: %ld\n",LONG_MAX);
	printf("signed long int minimum values: %ld\n",LONG_MIN);

	//unsigned types	
	
	printf("unsigned char maximum values: %u\n",UCHAR_MAX);
	printf("unsigned short int maximum values: %u\n",USHRT_MAX);
	printf("unsigned int maximum values: %u\n",UINT_MAX);
	printf("unsigned long int maximum values: %lu\n",ULONG_MAX);	
}


