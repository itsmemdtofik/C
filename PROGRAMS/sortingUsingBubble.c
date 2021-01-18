//   write a c program to display the array element using bouble sort technique    //
#include<stdio.h>
#include<stdlib.h>
int main()
{
  int a[100], n, i, j, temp;

  printf("Enter the value for n:\n");
  scanf("%d", &n);

  printf("enter the element of an array:\n");

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
printf("Before sorting:\n");
for(i=0; i<n; i++)
printf("%d\n",a[i]);

  for (i = 0 ; i < n - 1; i++)
  {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (a[j] > a[j+1]) /* For decreasing order use < */
      {
        temp       = a[j];
        a[j]   = a[j+1];
        a[j+1] = temp;
      }
    }
  }

  printf("After sorting:\n");

  for (i = 0; i < n; i++)
     printf("%d\n", a[i]);

  return 0;
}
