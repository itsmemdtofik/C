#include<stdio.h>
void exchange(int *,int *);
int main(){
	int a,b;
	a=12;
	b=11;
	printf("Before Exchanging =%d\t%d\t\n",a,b);
	exchange(&a,&b);
	printf("After Exchanging =%d\t%d\t\n",a,b );

}
void exchange(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;

}
