#include <stdio.h>

int main() {
    int numCustomers;
    printf("Enter the number of customers: ");
    scanf("%d", &numCustomers);

    int customerid[numCustomers], unitsconsumed[numCustomers];
    char customername[numCustomers][30];
    float chargesperunit[numCustomers], totalamount[numCustomers], surcharge[numCustomers];

    //  getting their details and calculating  their bill
    for (int i = 0; i < numCustomers; i++) {
        printf("\nEnter Customer ID for Customer %d: ", i + 1);
        scanf("%d", &customerid[i]);
        
        printf("Enter Customer Name for Customer %d: ", i + 1);
        scanf("%s", customername[i]);
        
        printf("Enter Units Consumed for Customer %d: ", i + 1);
        scanf("%d", &unitsconsumed[i]);

        // Charge per unit calculation
        if (unitsconsumed[i] <= 199) {
            chargesperunit[i] = 1.20;
        } else if (unitsconsumed[i] >= 200 && unitsconsumed[i] < 400) {
            chargesperunit[i] = 1.50;
        } else if (unitsconsumed[i] >= 400 && unitsconsumed[i] < 600) {
            chargesperunit[i] = 1.80;
        } else {
            chargesperunit[i] = 2.00;
        }

        // Calculate the total amount before surcharge
        totalamount[i] = unitsconsumed[i] * chargesperunit[i];

        // Add surcharge if total amount exceeds 400
        surcharge[i] = 0;
        if (totalamount[i] > 400) {
            surcharge[i] = totalamount[i] * 0.15;
            totalamount[i] += surcharge[i];
        }

        // Minimum bill is 100
        if (totalamount[i] < 100) {
            totalamount[i] = 100;
        }
    }

    // Display the bills for each customer
    for (int i = 0; i < numCustomers; i++) {
        printf("\nElectricity Bill for Customer %d\n", i + 1);
        printf("Customer ID: %d\n", customerid[i]);
        printf("Customer Name: %s\n", customername[i]);
        printf("Units Consumed: %d\n", unitsconsumed[i]);
        printf("Charges per Unit: Kshs. %.2f\n", chargesperunit[i]);
        printf("Total Amount to Pay: Kshs. %.2f\n", totalamount[i]);
    }

    return 0;
}