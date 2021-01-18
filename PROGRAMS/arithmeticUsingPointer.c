/** write a program to illustrate use of pointer in arithmatic operation.**/
#include <stdio.h>
#include <math.h>
int main()
{

 int a, b, *p1, *p2, x, y, z;
 a = 12;
 b = 4;
 p1 = &a;
 p2 = &b;
 x = (*p1) * (*p2) - 6;
 y = 4 * (-*p2) / (*p1) + 10;
 printf("a=%d\t b=%d\n", a, b);
 printf("x=%d\t y=%d\n", x, y);
 *p2 = *p2 + 3;
 *p1 = (*p2) - 5;
 z = (*p1) * (*p2) - 6;
 printf("a=%d\t b=%d\n", a, b);
 printf("z=%d\t", z);
}
