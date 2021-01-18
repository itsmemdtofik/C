/*
#include<stdio.h>
int main(void){
	int a=30;
	int *p;
	int **q;
	p=&a;
	q=&p;
	printf("%d\n",a );
	printf("%d\n",*p );
	printf("%d\n", **q);
}
*/
#include<stdio.h>
int main(void){
int a ;
int *p;
int **q;
int ***r;
p = &a; q = &p; r = &q;
printf("enter a number");
scanf("%d", &a);
printf("the number %d\n", a);

printf("enter a number");
scanf("%d", p);
printf("the number %d\n", a);
printf("enter a number");
scanf("%d", *q);
printf("the number %d\n", a);

printf("enter a number");
scanf("%d", **r);
printf("the number %d\n", a);
}
