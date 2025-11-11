#include <stdio.h>

int main() 
{
    int n, i;
    int marks[10];
    int highest, lowest;
    float sum = 0, average;

    int passed = 0, failed = 0;
    int Aplus = 0, A = 0, B = 0, C = 0, D = 0;

    printf("========== Student Performance Analyzer ==========\n");
    printf("Enter total number of students: ");
    scanf("%d", &n);

    if (n > 10 || n <= 0) {
        printf("Invalid number of students! (1–10 allowed)\n");
        return 0;
    }

    printf("Enter marks for each student:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
        sum += marks[i];

        if (i == 0) {
            highest = lowest = marks[i];
        } else {
            if (marks[i] > highest)
                highest = marks[i];
            if (marks[i] < lowest)
                lowest = marks[i];
        }

    
        if (marks[i] >= 90)
            Aplus++;
        else if (marks[i] >= 80)
            A++;
        else if (marks[i] >= 70)
            B++;
        else if (marks[i] >= 60)
            C++;
        else if (marks[i] >= 50)
            D++;
        else
            failed++;
    }

    average = sum / n;
    passed = n - failed;

    printf("========== Result Summary ==========\n");
    printf("Average Marks: %.2f\n", average);
    printf("Highest Marks: %d\n", highest);
    printf("Lowest Marks: %d\n", lowest);
    printf("Total Passed Students: %d\n", passed);
    printf("Total Failed Students: %d\n", failed);

    printf("Grade Distribution:\n");
    printf("A+ : %d\n", Aplus);
    printf("A  : %d\n", A);
    printf("B  : %d\n", B);
    printf("C  : %d\n", C);
    printf("D  : %d\n", D);
    printf("Fail : %d\n", failed);
    printf("====================================\n");

    return 0;
}

