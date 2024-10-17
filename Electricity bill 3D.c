//Here’s the regenerated 3D program to handle multiple customers across multiple months, and both peak and off-peak hours using a 3D array:

//3D Program (Handling multiple customers across multiple months and peak/off-peak consumption

#include <stdio.h>

int main() {
    int numCustomers, numMonths, numTypes = 2;  // Types: 0 = Off-peak, 1 = Peak

    printf("Enter the number of customers: ");
    scanf("%d", &numCustomers);

    printf("Enter the number of months: ");
    scanf("%d", &numMonths);

    int customerid[numCustomers], unitsconsumed[numCustomers][numMonths][numTypes];
    char customername[numCustomers][30];
    float chargesperunit[numCustomers][numMonths][numTypes], totalamount[numCustomers][numMonths], surcharge[numCustomers][numMonths];

    // Loop through each customer and each month/type to calculate the bill
    for (int i = 0; i < numCustomers; i++) {
        printf("\nEnter Customer ID for Customer %d: ", i + 1);
        scanf("%d", &customerid[i]);

        printf("Enter Customer Name for Customer %d: ", i + 1);
        scanf("%s", customername[i]);

        for (int j = 0; j < numMonths; j++) {
            totalamount[i][j] = 0; // Reset total amount for the month

            for (int k = 0; k < numTypes; k++) {
                printf("\nEnter Units Consumed for Customer %d in Month %d, %s Hours: ", i + 1, j + 1, k == 0 ? "Off-Peak" : "Peak");
                scanf("%d", &unitsconsumed[i][j][k]);

                // Charge per unit calculation
                if (unitsconsumed[i][j][k] <= 199) {
                    chargesperunit[i][j][k] = 1.20;
                } else if (unitsconsumed[i][j][k] >= 200 && unitsconsumed[i][j][k] < 400) {
                    chargesperunit[i][j][k] = 1.50;
                } else if (unitsconsumed[i][j][k] >= 400 && unitsconsumed[i][j][k] < 600) {
                    chargesperunit[i][j][k] = 1.80;
                } else {
                    chargesperunit[i][j][k] = 2.00;
                }

                // Add this to the total amount for the month
                totalamount[i][j] += unitsconsumed[i][j][k] * chargesperunit[i][j][k];
            }

            // Add surcharge if total amount exceeds 400
            surcharge[i][j] = 0;
            if (totalamount[i][j] > 400) {
                surcharge[i][j] = totalamount[i][j] * 0.15;
                totalamount[i][j] += surcharge[i][j];
            }

            // Minimum bill is 100
            if (totalamount[i][j] < 100) {
                totalamount[i][j] = 100;
            }
        }
    }

    // Display the bills for each customer and each month
    for (int i = 0; i < numCustomers; i++) {
        printf("\nElectricity Bill for Customer %d\n", i + 1);
        printf("Customer ID: %d\n", customerid[i]);
        printf("Customer Name: %s\n", customername[i]);

        for (int j = 0; j < numMonths; j++) {
            printf("\nMonth %d\n", j + 1);
            printf("Total Units Consumed (Peak + Off-Peak): %d\n", unitsconsumed[i][j][0] + unitsconsumed[i][j][1]);
            printf("Charges per Unit (Off-Peak): Kshs. %.2f\n", chargesperunit[i][j][0]);
            printf("Charges per Unit (Peak): Kshs. %.2f\n", chargesperunit[i][j][1]);
            printf("Total Amount to Pay for Month %d: Kshs. %.2f\n", j + 1, totalamount[i][j]);
        }
    }

    return 0;
}



