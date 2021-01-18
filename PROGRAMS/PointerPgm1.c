/** WAP to define an integer variable a
Define a pointer to integer and assign a’s address
Print a and its address
Print the pointer value containing the address of a  */

/* #include<stdio.h>
int main(void)
{
    int a;
    int *p;
    a = 14;
    p = &a;
    printf("%d %p\n", a, &a);
    printf("%p %d  %d\n", p, *p, a);
    return 0;
}
*/
/* c program using call by value
#include <stdio.h>
long add(long , long );
int main()
{
   long first, second, *p, *q, sum;

   printf("Input two integers to add\n");
   scanf("%ld%ld", &first, &second);

   sum = add(first, second);

   printf("(%ld) + (%ld) = (%ld)\n", first, second, sum);

   return 0;
}

long add(long x, long y) {
   long sum;

   sum = x + y;

   return sum;
}
*/
/** c program using call by reference using pointer

#include <stdio.h>
long add(long *, long *);
int main()
{
   long first, second, *p, *q, sum;

   printf("Input two integers to add\n");
   scanf("%ld%ld", &first, &second);

   sum = add(&first, &second);

   printf("(%ld) + (%ld) = (%ld)\n", first, second, sum);

   return 0;
}

long add(long *x, long *y) {
   long sum;

   sum = *x + *y;

   return sum;
}
*/

/** c program to find smallest using pointer
#include <stdio.h>
#include <stdlib.h>
void main()
{
 int fno,sno,*ptr1=&fno,*ptr2=&sno;

   printf("\n\n Pointer : Find the maximum number between two numbers :\n");
   printf("------------------------------------------------------------\n");

   printf(" Input the first number : ");
   scanf("%d", ptr1);
   printf(" Input the second  number : ");
   scanf("%d", ptr2);


 if(*ptr1<*ptr2)
 {
  printf("\n\n %d is the maximum number.\n\n",*ptr1);
 }
 else
 {
  printf("\n\n %d is the maximum number.\n\n",*ptr2);
 }

}

*/

/* c program to find smallest number using pointer
#include<stdio.h>
int smallest(int *a,int *b);
int main()
{

    int a,b;
    int *p,*q,c;
    p=&a;
    p=&b;
    printf("Enter toe number");
    scanf("%d%d",&a,&b);
    c=smallest(&a,&b);
    printf("Smallest number is=%d",c);
    return 0;

}
int smallest(int *x,int *y)
{

    if(*x<*y) return (*x);
    else return (*y);



}
*/

/** C program to swapping of two number using pointer
#include<stdio.h>
int swap(int *,int *);
int main()
{

    int a,b,c;
    int *p,*q;
    p=&a;
    q=&b;
    printf("Enter two number");
    scanf("%d%d",&a,&b);
    printf("before swapping of two bumber is %d %d\n",a,b);
    swap(&a,&b);
    printf("\nafter swapping of two bumber is %d %d",a,b);
    return 0;

}

int swap(int *x,int *y)
{

    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
    return ;

}
*/
/* swapping three number using pointer and find largest number among three
#include <stdio.h>
void Swap(int *n1, int *n2, int *n3)
{
    int temp;
    temp = *n2;
    *n2 = *n1;
    *n1 = *n3;
    *n3 = temp;
}
int largest(int *x,int *y,int *z)
{
    if(*x > *y)
    {
        if(*x > *z)
        {
            return *x;
        }
        else
        {
            return *z;
        }
    }
    else
    {
        if(*y > *z)
        {
            return *y;
        }
        else
        {
           return *z;
        }
    }
}
int main()
{
    int a, b, c;
    int *p,*q,*r,s;
    p=&a;
    q=&b;
    r=&c;

    printf("Enter a, b and c :  ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Value before swapping:\n");
    printf("\t\ta = %d \nb = %d \nc = %d\n", a, b, c);

    Swap(&a, &b, &c);

    printf("Value after swapping:\n");
    printf("a = %d \nb = %d \nc = %d", a, b, c);
    s=largest(&a,&b,&c);
    printf("\t\tThe largest number is %d",c);

    return 0;
}

*/
/** function returning to the pointer
*prototype declaration
#include<stdio.h>
int *smaller(int *x,int *y)
{
    /*if(*x<*y)
         return *x;
     else return *y;
    return (*x<*y ? x:y);

}
int main(void)
{
    int a;
    int b;
    int *p;
    printf("Enter two number");
    scanf("%d%d",&a,&b);
    p=smaller(&a,&b);
    printf("The smallest number is =%d",*p);
}
*/

/* pointer to a pointer to an integer
#include<stdio.h>
int main(void){

    int a=78;
    int *p;
    int **q;
    p=&a;
    q=&p;
    printf("The value of a is = %3d\n",a);
    printf("The value of *p is = %3d\n",*p);
    printf("The value of **q is = %3d\n",**q);



}*/

/** Program to find smallest number in among 4

#include<stdio.h>

int main(void)
{

    int array[100],*minimum,size,i,location=1;
    printf("Enter the size of number : ");
    scanf("%d",&size);
    printf("Enter the number of element of an array  : ");
    for(i=0; i<size; i++)
        scanf("%d",&array[i]);
    minimum=array;
    *minimum=*array;
    for(i=0; i<size; i++)
    {

        if(*(array+i)<*minimum)
        {

            *minimum=*(array+i);
            location=i+1;
        }
    }
    printf("Minimum element present at location number %d and %d\n",location,*minimum);





}

*/
/*
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int *ptr;
    int n, i;
    n = 5;
    printf("Enter the number of element %d\n", n);
    ptr = ((int *) malloc(n * sizeof(int)));
    if (ptr == NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    else
    {
        printf("Memory successfully allocated\n");
        for (i = 0; i < 5; i++)
        {
            ptr[i] = i + 1;
        }
        printf("The element of an array is\n");
        for (i =0; i < 5; i++)
        {
            printf("%6d", ptr[i]);
        }
    }

}
*/
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int *ptr;
    int n, i;
    n = 5;
    printf("Enter the size of an array = %d \n",n);

    ptr = (int *) calloc(n, sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    else
    {
        printf("Memory successfully allocated\n");
        for (i = 0; i < n; i++)
        {
            ptr[i] = i + 1;
        }
        printf("The element of an array is\n");
        for (i = 0; i < n; i++)
        {
            printf("%6d\n", ptr[i]);
        }

        n=10;
        printf("Enter the new size of an array element = %d\n",n);
        ptr=realloc(ptr,n*sizeof(int));
        printf("Memory allocated successfully re-allocated\n");
        for(i=5; i<n; i++)
        {
            ptr[i]=i+1;
        }
        printf("The element of an array are : \n");
        for(i=0; i<n; i++)
        {
            printf("%6d\n",ptr[i]);
        }
        free(ptr);

    }

}
