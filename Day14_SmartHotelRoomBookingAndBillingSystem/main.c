#include <stdio.h>

int main()
{
    int customers, roomType, days, totalRooms=0;
    char name[50];
    char breakfast, wifi, gym;
    float rate, baseFare, addServices, subtotal, discount, gst, finalBill;
    float totalRevenue=0 , highestBill=0 , lowestBill = 999999;

    printf("========= Smart Hotel Room Booking System =========\n");
    printf("Enter total number of customers: ");
    scanf("%d", &customers);

    int i = 1;
    while (i <= customers)
    {
        printf("\n--- Customer %d ---\n", i);
        printf("Enter customer name: ");
        scanf("%s", name);

        printf("Enter room type (1-Deluxe, 2-Super Deluxe, 3-Suite): ");
        scanf("%d", &roomType);
        printf("Enter number of days: ");
        scanf("%d", &days);

        printf("Breakfast (Y/N): ");
        scanf(" %c", &breakfast);
        printf("Wi-Fi (Y/N): ");
        scanf(" %c", &wifi);
        printf("Gym Access (Y/N): ");
        scanf(" %c", &gym);


        if (roomType == 1)
            rate = 2500;
        else if (roomType == 2)
            rate = 4000;
        else if (roomType == 3)
            rate = 6000;
        else
        {
            printf("Invalid room type! Defaulting to Deluxe Room.\n");
            rate = 2500;
        }

        baseFare = rate * days;
        addServices = 0;

        if (breakfast == 'Y' || breakfast == 'y')
            addServices += 300 * days;
        if (wifi == 'Y' || wifi == 'y')
            addServices += 100 * days;
        if (gym == 'Y' || gym == 'y')
            addServices += 200 * days;

        subtotal = baseFare + addServices;

    
        if (subtotal > 10000)
            discount = subtotal * 0.10;
        else
            discount = 0;

        gst = (subtotal - discount) * 0.12;
        finalBill = (subtotal - discount) + gst;

        printf("\n--- Bill for %s ---", name);
        printf("\nBase Fare: ₹%.0f", baseFare);
        printf("\nAdditional Services: ₹%.0f", addServices);
        printf("\nSubtotal: ₹%.0f", subtotal);
        printf("\nDiscount: ₹%.0f", discount);
        printf("\nGST (12%%): ₹%.0f", gst);
        printf("\nFinal Bill: ₹%.0f\n", finalBill);

    
        totalRevenue += finalBill;
        totalRooms++;

        if (finalBill > highestBill)
            highestBill = finalBill;
        if (finalBill < lowestBill)
            lowestBill = finalBill;

        i++;
    }

    printf("\n========== Hotel Summary ==========\n");
    printf("Total Rooms Booked: %d\n", totalRooms);
    printf("Total Revenue: ₹%.0f\n", totalRevenue);
    printf("Highest Bill: ₹%.0f\n", highestBill);
    printf("Lowest Bill: ₹%.0f\n", lowestBill);
    printf("===================================\n");

    return 0;
}
