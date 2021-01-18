#include <stdio.h>
#include <stdlib.h>
long amount = 1000, deposit, withdraw;
int choice, pin, k;
char transaction, n, N;
void main(void)
{

    while (pin != 1111)
    {
        printf("\n Enter Your Pin Number:  ");
        scanf("\n %d", &pin);
        if (pin != 1111)
            printf("\n Please Enter a Valid Pin Number :\n");
    }
    do
    {
        printf("\n*************Welcome to ATM Machine Service***************\n");
        printf("\n 1-Check Balance\n");
        printf("\n 2-Withdraw\n");
        printf("\n 3-Deposit\n");
        printf("\n 4-Exit\n");
        printf("\n *********************************************\n");
        printf("\n Enter The Choice :  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n This is Your Balance Rs ===  %d\n", amount);
            break;

        case 2:
            printf("\n Enter the Amount to Withdraw  :  ");
            scanf("%d", &withdraw);
            if (withdraw % 100 != 0)
            {

                printf("\n Please Enter the amount in Multiple of 100");
            }
            else if (withdraw > (amount - 500))
            {

                printf("\n This is your Insufficient Balance \n");
            }
            else
            {
                amount = amount - withdraw;
                printf("\n Please Collect to your cash ***");
                printf("\n Your Current Balance is === %d\n", amount);
            }
            break;
        case 3:
            printf("\n Enter the amount to Deposit : ");
            scanf("%d", &deposit);
            amount = amount + deposit;
            printf("\n Your Balance is === %d", amount);
            break;
        case 4:

            printf("\n ************* Thank You for using ATM ****************");
            exit(0);
            break;
        default:
            printf("*************  This is Invalid Choice  **************");
        }
        fflush(stdin);
        scanf("%c", &transaction);
        if (transaction == n || transaction == N)
            k = 1;
    } while (!k);
}
