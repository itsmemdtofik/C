//Quick_sort method in Design and Analysis of an Algorithm//


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int a[],int low,int high)
{
    int i,j,key,temp;
    i=low;
    key=a[low];
    j=high+1;

    while(i<=j)
    {
        do i=i+1;
        while(key>=a[i]);
        do j=j+1;
        while(key<a[j]);
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            temp=a[low];
            a[low]=a[j];
            a[j]=temp;
        }
    }
    return j;
}
void quick_sort(int a[],int low,int high)
{
    int j;
    if(low<high)
    {
        j=partition(a,low,high) ;
        quick_sort(a,low,j-1);
        quick_sort(a,j+1,high);
    }
}
void main()
{
    int n1,n2,n,i,a[9000];
    double time1,time2;
    clock_t begin1,end1,begin2,end2;
    printf("Enter the input size  :\n");
    scanf("%d",&n);
    for(i=0; i<n1; i++)
        a[i]=rand()%100;
    begin1=clock();
    quick_sort(a,0,n1-1);
    printf("Sorted element are :\n");
    for(i=0; i<n1; i++)
        printf("\t %d",a[i]);
    end1=clock();
    printf("\n Enter the size of input  :\n");
    scanf("%d",&n);
    for(i=0; i<n2; i++)
        a[i]=rand()%100;
    begin2=clock();
    quick_sort(a,0,n2-1);
    printf("\n The sorted element are  \n");
    for(i=0; i<n2; i++)
        printf("\t %d",a[i]);
    end2=clock();
    time1=(double)(end1-begin1)/CLOCKS_PER_SEC;
    printf(" \n Time to sort input size %d is =%f",n1,time1);
    time2=(double)(end2-begin2)/CLOCKS_PER_SEC;
    printf("\n Time to sort input size %d is= %f",n2,time2);



}

