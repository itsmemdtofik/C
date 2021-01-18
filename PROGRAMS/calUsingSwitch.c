
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void main()
{
    int a,b;
    int choice;
    while(1)
    {
        printf("-------------------------------------\n");
        printf("1-Addition\n");
        printf("2-Subtraction\n");
        printf("3-Multiplication\n");
        printf("4-Division\n");
        printf("5-Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the two number:\n");
                   scanf("%d%d",&a,&b);
                   printf("Addition of %d and %d is=%d\n",a,b,a+b);
                   break;

            case 2:printf("Enter the two number:\n");
                   scanf("%d%d",&a,&b);
                   printf("Subtraction of %d and %d is=%d\n",a,b,a-b);
                   break;

            case 3:printf("Enter the two number:\n");
                   scanf("%d%d",&a,&b);
                   printf("Multiplication of %d and %d is=%d\n",a,b,a*b);
                   break;

            case 4:printf("Enter the two number:\n");
                   scanf("%d%d",&a,&b);
                   printf("Division of %d and %d is=%d\n",a,b,a/b);
                   break;
            case 5: exit(0);
                    break;
            default :printf("Wrong selection...?\n");
                     break;

        }
    }

}
