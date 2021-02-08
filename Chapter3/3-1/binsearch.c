#include<stdio.h>

int binsearch(int x,int v[],int n); 

main(){
	int v[10] ={1,2,3,4,5,6,7,8,9,10};
	printf("%d\n",binsearch(10,v,10));

}

int binsearch(int x,int v[],int n){

	int low,high,mid;
	
	low = 0;
	high = n - 1;
	mid = (low+high)/2;

	while(low < high){
		if(x<=v[mid]){
			high = mid;
		}else{
			low = mid+1;
		}
		mid = (high+low)/2;
	}
	
	if(x == v[mid]){
		return mid;
	}else{
		return -1;
	}
}
