
#include<stdio.h>
 
// Assuming n-th disk is bottom disk (count down)
void tower(int n, char sourcePole, char destinationPole, char auxiliaryPole)
{
   // Base case (termination condition)
   if(n== 0 )
     return;
 
   // Move first n-1 disks from source pole
   // to auxiliary pole using destination as
   // temporary pole
   tower(n-1, sourcePole, auxiliaryPole,
      destinationPole);
 
    // Move the remaining disk from source
   // pole to destination pole
   printf("Move the disk %d from %c to %c\n", 
    n,sourcePole, destinationPole);
 
   // Move the n-1 disks from auxiliary (now source)
   // pole to destination pole using source pole as
   // temporary (auxiliary) pole
   tower(n-1, auxiliaryPole, destinationPole,
     sourcePole);
}
 
int main()
{  
   int n;
   printf("Enter the number of Disk : ");
   scanf("%d",&n);
   tower(n, 'S', 'D', 'A');
    
   return 0;
}
