# include<stdio.h>
# include<stdlib.h>
int main()
{
    int rowNum, colNum, i, j;
    int **table;
    printf("\n enter the number of rows \n");
    scanf("%d", &rowNum);
    table = (int **) calloc(rowNum+1, sizeof(int *));
    for (i = 0; i < rowNum; i++)  /* this will tell which row we are in */
    {
        printf("enter size of %6d row\n", i+1);
        scanf("%d", &colNum);
        table[i] = (int *) calloc(colNum+1, sizeof(int));
        printf("\n enter %6d row elements \n", i+1);
        for (j = 1; j <= colNum;  j++)
        {
            scanf("%d", &table[i][j]);
        }
        table[i][0] = colNum;
        printf("size of row number [%d] = %6d\n", i+1, table[i][0]);
    }
    table[i] = NULL;
    for (i = 0; i < rowNum; i++) /* this will tell which row we are in */
    {
        printf("displaying %d row elements\n", i+1);
        for (j = 0; j <= *table[i];  j++)
        {
            printf("%6d\n", table[i][j]);
        }
        printf("\n");
    }
    return 0;
}
