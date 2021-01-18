/** write a program to swap two number using cal by value and call by reference
parameter passing techniques **/

#include <stdio.h>
swap_by_value(int a, int b)

{

 int temp;
 temp = a;
 a = b;
 b = temp;
 printf("---------------------------\n");
 printf("in swap by value\n");
 printf("a=%d\t b=%d\n", a, b);
 printf("-----------------------------\n");
}
swap_by_ref(int *a, int *b)
{

 int temp;
 temp = *a;
 *a = *b;
 *b = temp;
}
int main()
{
 int m = 10, n = 20;
 printf("before swap by value\n");
 printf("m=%d\t n=%d\n", m, n);
 swap_by_value(m, n);
 printf("after swap by value\n");
 printf("m=%d\t n=%d\n", m, n);
 printf("----------------------------\n");

 printf("before swap by refrence\n");
 printf("m=%d\t n=%d\n", m, n);
 swap_by_ref(&m, &n);

 printf("after swap by refrence\n");
 printf("m=%d\t n=%d\n", m, n);
}
