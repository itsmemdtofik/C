/*typedef struct
{
    int id;
    char name[20];
    float percentage;
} STUDENT;



int main()
{
    STUDENT student;
    student.id=1;
    strcpy(student.name, "Raju");
    student.percentage = 86.5;
    printf(" Id is: %d \n", student.id);
    printf(" Name is: %s \n", student.name);
    printf(" Percentage is: %f \n", student.percentage);
    return 0;
}
*/
// An example program to demonstrate working
// of enum in C

#include<stdio.h>
typedef struct{
int x,y;


}POINT;
int main()
{
    POINT p1={0,1};
    // pointer for var
    POINT* ptr1=&p1;


    // double pointer for ptr2
    POINT** ptr2=&ptr1;


    printf("Value of var = %d\n", p1 );
    printf("Value of var using single pointer = %d\n", ptr1->x );
    printf("Value of var using double pointer = %d\n", (*ptr2)->y);

  return 0;
}

