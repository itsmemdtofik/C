
// write a c program to display the array of element using selection sort technique //

#include <stdio.h>
 
int main()
{
  int a[100], n, i, j, pos, temp;
 
  printf("Enter the value for n:\n");
  scanf("%d", &n);
 
  printf("enter the element:\n");
 
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("Before sorting:\n");
  for(i=0; i<n; i++)
    printf("%d\n",a[i]);
 
  for (i = 0; i < (n - 1); i++)
  {
    pos = i;
   
    for (j = i + 1; j < n; j++)
    {
      if (a[pos] > a[j])
        pos = j;
    }
    if (pos != j)
    {
      temp = a[i];
      a[i] = a[pos];
      a[pos] = temp;
    }
  }
 
  printf("After sorting:\n");
 
  for (i = 0; i < n; i++)
    printf("%d\n", a[i]);
return 0;
}
