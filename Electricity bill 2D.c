#include <stdio.h>

int main() {

    int numCustomers, numMonths;
    
    printf("Enter the number of customers: ");
    scanf("%d", &numCustomers);
    
    printf("Enter the number of months: ");
    scanf("%d", &numMonths);

    int customerid[numCustomers], unitsconsumed[numCustomers][numMonths];
    char customername[numCustomers][30];
    float chargesperunit[numCustomers][numMonths], totalamount[numCustomers][numMonths], surcharge[numCustomers][numMonths];

    // Loop through each customer and each month to calculate the bill
    for (int i = 0; i < numCustomers; i++) {
        printf("\nEnter Customer ID for Customer %d: ", i + 1);
        scanf("%d", &customerid[i]);

        printf("Enter Customer Name for Customer %d: ", i + 1);
        scanf("%s", customername[i]);

        for (int j = 0; j < numMonths; j++) {
            printf("\nEnter Units Consumed for Customer %d in Month %d: ", i + 1, j + 1);
            scanf("%d", &unitsconsumed[i][j]);

            // Charge per unit calculation
            if (unitsconsumed[i][j] <= 199) {
                chargesperunit[i][j] = 1.20;
            } else if (unitsconsumed[i][j] >= 200 && unitsconsumed[i][j] < 400) {
                chargesperunit[i][j] = 1.50;
            } else if (unitsconsumed[i][j] >= 400 && unitsconsumed[i][j] < 600) {
                chargesperunit[i][j] = 1.80;
            } else {
                chargesperunit[i][j] = 2.00;
            }

            // Calculate the total amount before surcharge
            totalamount[i][j] = unitsconsumed[i][j] * chargesperunit[i][j];

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
            printf("Units Consumed: %d\n", unitsconsumed[i][j]);
            printf("Charges per Unit: Kshs. %.2f\n", chargesperunit[i][j]);
            printf("Total Amount to Pay: Kshs. %.2f\n", totalamount[i][j]);
        }
        
    }
    

    return 0;
}