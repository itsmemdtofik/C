#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,n,n1,a[20],pass;
    char mobno[100];
    char fname[100],lname[100],add[100];
    char uname[100];
    int choice;

    while(1)
    {
        printf("------------------------------------\n");
        printf("1-Register\n");
        printf("2-Login\n");
        printf("3-Exit\n");
        printf("------------------------------------\n");
        printf("\nEnter your choice  :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter the First Name  :\n");
            scanf("%s",fname);
            printf("\nEnter the Last Name  :\n");
            scanf("%s",lname);
            printf("\nEnter the Mobile Number  :\n");
            scanf("%s",mobno);
            printf("\nEnter the address  :\n");
            scanf("%s",add);
            printf("\n");
            printf("------------------------------------\n");
            printf("\nThe First Name is==%s",fname);
            printf("\nThe Last Name is==%s",lname);
            printf("\nThe Mobile Number is==%s",mobno);
            printf("\nThe address is ==%s\n",add);
            break;

        case 2:
            printf("\nEnter the UserName  :");
            scanf("%s",uname);
            printf("\nEnter the Password  :");
            scanf("%d",&n);
            printf("------------------------------------\n");
            printf("\n The UserName is ==%s",uname);
            printf("\n The Password is ==%d\n",n);
            break;
        case 3:
            exit(1);
            break;
        default:
            printf("Invalid Selection\n");

        }
    }

}
