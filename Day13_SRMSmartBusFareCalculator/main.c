#include <stdio.h>

int main() 
{
    int  passengers, i=1 , age, time;
    char name[50];
    double distance, baseFare, finalFare, totalRevenue, highestFare, lowestFare=999999;


    printf("========= SRM Smart Bus Fare Calculator =========\n\n");
    printf("Enter number of passengers: ");
    scanf("%d", &passengers);

    while (i <= passengers) 
    {
        printf("\n--- Passenger %d ---\n", i);
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter age: ");
        scanf("%d", &age);
        printf("Enter distance (in km): ");
        scanf("%lf", &distance);
        printf("Enter travel time (24-hour format): ");
        scanf("%d", &time);

        baseFare = distance * 10;
        finalFare = baseFare;

        if (age < 12) 
        {
            finalFare = baseFare * 0.5;
            printf("Passenger: %s | Base Fare: ₹%.0f | Child Discount Applied", name, baseFare);
        }
        
        else if (age >= 60) 
        {
            finalFare = baseFare * 0.7;
            printf("Passenger: %s | Base Fare: ₹%.0f | Senior Citizen Discount Applied", name, baseFare);
        }

        else 
        {
            printf("Passenger: %s | Base Fare: ₹%.0f", name, baseFare);
        }

        if ((time >= 8 && time <= 10) || (time >= 17 && time <= 20)) 
        {
            finalFare = finalFare * 1.2;
            printf(" | Peak Hour Surcharge Applied");
        }

        if (finalFare < 20) 
        {
            finalFare = 20;
        }

        printf(" | Final Fare: ₹%.0f\n", finalFare);

        totalRevenue += finalFare;

        if (finalFare > highestFare)
            highestFare = finalFare;

        if (finalFare < lowestFare)
            lowestFare = finalFare;

        i++;
    }


    printf("\n========= Daily Summary =========\n");
    printf("Total Passengers: %d\n", passengers);
    printf("Total Revenue Collected: ₹%.0f\n", totalRevenue);
    printf("Highest Fare: ₹%.0f\n", highestFare);
    printf("Lowest Fare: ₹%.0f\n", lowestFare);

    return 0;
}
