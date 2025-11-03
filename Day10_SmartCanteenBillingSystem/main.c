#include <stdio.h>

int main() 
{
    int totalCustomers;
    float totalRevenue = 0;

     printf("==== Smart Canteen Billing System ====\n");

    printf("Enter total number of customers: ");
    scanf("%d", &totalCustomers);

    for (int c = 1; c <= totalCustomers; c++) 
    {
        int numItems, code, qty;
        float itemPrice = 0, total = 0, discount = 0, finalBill = 0;

        printf("--- Customer %d ---\n", c);
        printf("Enter number of items: ");
        scanf("%d", &numItems);

        for (int i = 1; i <= numItems; i++) 
        {
            printf("Enter item code: ");
            scanf("%d", &code);
            printf("Enter quantity: ");
            scanf("%d", &qty);

            switch (code) 
            {
                case 1: itemPrice = 80.0f;  printf("Sandwich x %d = ₹%.2f\n", qty, (float)qty * itemPrice); break;
                case 2: itemPrice = 120.0f; printf("Burger x %d = ₹%.2f\n", qty, (float)qty * itemPrice); break;
                case 3: itemPrice = 150.0f; printf("Pizza Slice x %d = ₹%.2f\n", qty, (float)qty * itemPrice); break;
                case 4: itemPrice = 60.0f;  printf("Coffee x %d = ₹%.2f\n", qty, (float)qty * itemPrice); break;
                case 5: itemPrice = 50.0f;  printf("Juice x %d = ₹%.2f\n", qty, (float)qty * itemPrice); break;              default: 
                    printf("Invalid item code!\n");
                    itemPrice = 0.0f; 
                    qty = 0;
            }

            total += (float)(qty) * itemPrice;
        }

        if (total > 500.0f) discount = total * 0.10f;
        finalBill = total - discount;
        totalRevenue += finalBill;

        printf("Customer %d Bill:\n", c);
        printf("Total: ₹%.2f\n", total);
        if (discount > 0)
            printf("Discount (10%%): ₹%.2f\n", discount);
        printf("Final Bill: ₹%.2f\n", finalBill);
    }

    printf("==== Canteen Summary ====\n");
    printf("Total Customers Served: %d\n", totalCustomers);
    printf("Total Revenue: ₹%.2f\n", totalRevenue);
    printf("===o===\n");

    return 0;
}
