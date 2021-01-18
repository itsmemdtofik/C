#include <stdio.h>
#include<time.h>


void main()
{
    int age,time1,time2,time3,time4,time5,stime;
    int ttime=24,total;


printf("Enter the data in WHOLE NUMBERS ONLY.");
printf("\n\nEnter your Current Age: ");
scanf("%d",&age);
printf("Enter the number of hours you sleep in a day: ");
scanf("%d",&time1);
printf("Enter the number of hours spent in work/college (include transportation time): ");
scanf("%d",&time2);
printf("Enter the number of hours you spend on watching T.V., Youtube, and other forms of entertainment: ");
scanf("%d",&time3);
printf("Enter the number of hours you eat in a day (such as breakfast, lunch & dinner): ");
scanf("%d",&time4);
printf("Enter the number of hours you spend grooming yourself in a day (brushing teeth, bathing, shaving, etc): ");
scanf("%d",&time5);

stime=total-time1-time2-time3-time4-time5;

printf("\n your save time is remaining::%d",stime);

	printf("\nYou get only %d hours every day to enjoy/explore yourself!",time3);

}



