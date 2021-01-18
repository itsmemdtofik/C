//   write a c program to find the largest of three number  //
#include<stdio.h>

int main()
{
    int a,b,c;
    printf("Enter theree number:  ");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)
    {
        if(a>c)
        {
            printf("a is the greatest number \n");
        }

    }
    if(b>a)
    {
        if(b>c)
        {

            printf("b is the greatest number \n");
        }

        else
        {
            printf("c is the greatest number \n");
        }
    }
}
