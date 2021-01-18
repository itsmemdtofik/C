/* write a program to store student record using structure and sorting with key */

#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int roll_no,marks;
    char name[25];
} STUDENT;

STUDENT student[100];
STUDENT temp;

void main()
{
    int i,j,n;
    printf("Enter the no of students\n");
    scanf("%d",&n);
    printf("enter student info as roll_no , name , marks\n");
    for(i=0; i<n; i++)
    {
        printf("Enter the details of student : ",i+1);
        scanf("%d %s %d",&student[i].roll_no,student[i].name,&student[i].marks);
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(student[j].marks<student[j+1].marks)
            {
                temp=student[j];
                student[j]=student[j+1];
                student[j+1]=temp;
            }
        }
    }

    printf("\nStudent info in terms of marks from highest to lowest\n");
    printf("\nROLL_NO\t\tNAME\t\tMARKS\n");
    printf("-------------------------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t\t\t%s\t\t\t%d\n",student[i].roll_no,student[i].name,student[i].marks);
    }
}
