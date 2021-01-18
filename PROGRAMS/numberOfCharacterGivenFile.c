/** write a c program to count the number of character in a given file **/

#include<stdio.h>

int main()
{
	FILE *f1;
	char c;
	int count=0;
	f1=fopen("input.text","w");
	while((c=getchar())!=EOF)
	putc(c,f1);
	fclose(f1);
	f1=fopen("input.text","r");
	while((c=getc(f1))!=EOF)
	{
		printf("%c\n",c);
		count++;
	}
	fclose(f1);
	printf("Number of character in the file is=%d\n",count);

}
