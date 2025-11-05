#include <stdio.h>

int main() 
{
    int choice, transactions = 0;
    double balance = 10000.0, amount;

    printf("======= Mini ATM Simulator =======\n");
    printf("Initial Balance: ₹%.0lf\n", balance);

    do 
    {
        printf("\n1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) 
        {
            printf("Your Current Balance: ₹%.2lf\n", balance);
            transactions++;
        }

        else if (choice == 2) 
        {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);

            if (amount > 0)
            {
                balance += amount;
                printf("Amount Deposited Successfully!\n");
                printf("Updated Balance: ₹%.2lf\n", balance);
                transactions++;
            }
            else
            {
                printf("Invalid deposit amount!\n");
            }
        }

        else if (choice == 3) 
        {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);

            if (amount <= 0)
            {
                printf("Invalid withdrawal amount!\n");
            }
            else if (amount > balance - 500)
            {
                printf("Insufficient balance! Minimum ₹500 must remain.\n");
            }
            else
            {
                balance -= amount;
                printf("Withdrawal Successful! Remaining Balance: ₹%.2lf\n", balance);
                transactions++;
            }
        }

        else if (choice == 4) 
        {
            printf("Thank you for banking with us!\n");
        }

        else 
        {
            printf("Invalid choice! Please try again.\n");
        }

        if (transactions >= 5)
        {
            printf("\nMaximum 5 transactions reached.\n");
            break;
        }

    } while (choice != 4);

    printf("\n======= Transaction Summary =======\n");
    printf("Total Transactions: %d\n", transactions);
    printf("Final Balance: ₹%.2lf\n", balance);
    printf("Session Ended.\n");

    return 0;
}
