//   write a c program to check whether the given number is unique or not using array  //

#include <stdio.h>
int main()
{
  int a[100], search,count=0, i, n;
 
  printf("Enter the size of an array : ");
  scanf("%d", &n);
 
  printf("Enter %d integer(s) : ", n);
 
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
 
  printf("Enter a number to search : ");
  scanf("%d", &search);
 
  for (i = 0; i < n; i++)
  {
    if (a[i] == search)    /* If required element is found */
    {
      printf("%d is found at location : %d\n", search, i+1);
      count++;
     break;
      
    }
  }
  if(count==0)
  {
  	printf("%d is the unique number",search);
  }
  else
  {
  	printf("%d is not the Unique number",search);
  	
  }
}
