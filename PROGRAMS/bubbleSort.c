#include <stdio.h>
#include <stdlib.h>
void main()
{
 int a[100], i, j, n, temp;
 printf("Enter the size of an element\n");
 scanf("%d", &n);
 printf("Enter the lement\n");
 for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
 printf("Before sorting\n");
 for (i = 0; i < n; i++)
		printf("%d\n", a[i]);
 for (i = 0; i < n - 1; i++)
 {
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
 }
 printf("After sorting\n");
 for (i = 0; i < n; i++)
		printf("%d\n", a[i]);
}
