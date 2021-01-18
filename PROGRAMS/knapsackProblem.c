#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{

    if(a>b)
    {

        return a;
    }
    return b;
}
void knapsack(int n,int m,int w[20],int p[20])
{

   int i,j;
   int v[20][20];
   for(i=0;i<=n; i++)
   {
       for(j=0; j<=m; j++)
       {
           if(i==0 || j==0)
           {
               v[i][j]=0;
           }
           else if(w[i]>j)
           {
               v[i][j]=v[i-1][j];
           }
           else
           {
               v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
           }
       }
   }
   printf("\n Output is\n");
   for(i=0;i<=n; i++)
   {
       for(j=0;j<=m; j++)
       {
           printf("\t%d",v[i][j]);
       }
       printf("\n");
   }
   printf("Optimal solution is==%d",v[n][m]);

}

int main()
{
    int i;
    int p[20];
    int w[20];
    int n;
    int m;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    printf("\n Enter teh weight of following object :\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    printf("\n Enter the profit of following object:\n");

        for(i=1;i<=n;i++)
        {
            scanf("%d",&p[i]);
        }
        printf("\n Enter capacity of knapsack :\n");
        scanf("%d",&m);
        knapsack(n,m,w,p);
        return 0;
        
    }

