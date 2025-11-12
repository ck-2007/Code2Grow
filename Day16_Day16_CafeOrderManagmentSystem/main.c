#include <stdio.h>

int main() 
{
    
    int prices[5] = {50, 30, 80, 120, 60};
    char items[5][20] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};
    int qtysold[5] ;
    int customer, itemCount, itemNo, qty;
    int sold = 0;
    float revenue = 0;

    printf("========== Cafe Order Management System ==========\n");

    printf("------- MENU -------\n");
    printf("Item No.  Item Name   Price (₹)\n");
    for (int i = 0; i < 5; i++) 
    {
        printf("   %d \t   %-10s \t ₹%d \n", i + 1, items[i], prices[i]);
    }

    printf("Enter total number of customers : ");
    scanf("%d", &customer);

    for (int c = 1; c <= customer; c++) 
    {
        float customerBill = 0;

        printf("--- Customer %d ---\n", c);
        printf("Enter number of items: ");
        scanf("%d", &itemCount);

        printf("Enter item number and quantity:\n");
        for (int i = 0; i < itemCount; i++) {
            scanf("%d %d", &itemNo, &qty);

            if (itemNo >= 1 && itemNo <= 5 && qty > 0) {
                customerBill += prices[itemNo - 1] * qty;
                qtysold[itemNo - 1] += qty;
                sold += qty;
            } else {
                printf("Invalid item number or quantity! Skipped.\n");
            }
        }

        printf("Total Bill for Customer %d: ₹%.2f\n", c, customerBill);
        revenue += customerBill;
    }

    int most = 0, least = 0;
    for (int i = 1; i < 5; i++) {
        if (qtysold[i] > qtysold[most])
            most = i;
        if (qtysold[i] < qtysold[least])
            least = i;
    }

    printf("========== Cafe Summary ==========\n");
    printf("Total Revenue: ₹%.2f\n", revenue);
    printf("Total Items Sold: %d\n", sold);
    printf("Most Ordered Item: %s\n", items[most]);
    printf("Least Ordered Item: %s\n", items[least]);

    return 0;
}
