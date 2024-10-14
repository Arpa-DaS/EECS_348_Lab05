#include <stdio.h>   
#include <stdlib.h>  

#define NUM_MONTHS 12  // Define a constant to represent the number of months in a year (12). This improves code readability and maintainability.

// Declare an array of constant strings to store the names of the months.
// 'const char*' means each element of the array is a pointer to a constant string (the month names).
const char *months[NUM_MONTHS] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Function to display the monthly sales report.
// It takes an array of sales (floats) as input.
void displayMonthlySalesReport(float sales[]) {
    // Print the header of the report.
    printf("\nMonthly Sales Report for 2024\n");
    printf("Month\t\tSales\n");

    // Loop through each month and print the month name along with its sales value.
    for (int i = 0; i < NUM_MONTHS; i++) {
        // %-10s: Left-align the month name and ensure it takes up at least 10 characters.
        // %.2f: Print the sales as a floating-point number with 2 decimal places.
        printf("%-10s\t%.2f\n", months[i], sales[i]);  // Print month and sales value.
    }
}

// Function to calculate and display the sales summary (minimum, maximum, and average sales).
// It takes an array of sales as input.
void displaySalesSummary(float sales[]) {
    // Initialize minSales and maxSales to the sales of the first month.
    // totalSales is initialized to 0 to accumulate the total sales for the average.
    float minSales = sales[0], maxSales = sales[0], totalSales = 0;
    int minIndex = 0, maxIndex = 0;  // Variables to store the index of the min and max sales.

    // Loop through the sales array to find the minimum, maximum, and total sales.
    for (int i = 0; i < NUM_MONTHS; i++) {
        totalSales += sales[i];  // Add the current month's sales to the total.

        // If the current sales value is smaller than minSales, update minSales and store the index.
        if (sales[i] < minSales) {
            minSales = sales[i];
            minIndex = i;
        }

        // If the current sales value is greater than maxSales, update maxSales and store the index.
        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxIndex = i;
        }
    }

    // Calculate the average sales by dividing total sales by the number of months.
    float averageSales = totalSales / NUM_MONTHS;

    // Print the summary report (min, max, and average sales).
    printf("\nSales summary report:\n");
    printf("Minimum sales: %.2f (%s)\n", minSales, months[minIndex]);  // Print min sales and corresponding month.
    printf("Maximum sales: %.2f (%s)\n", maxSales, months[maxIndex]);  // Print max sales and corresponding month.
    printf("Average sales: %.2f\n", averageSales);  // Print average sales.
}

// Function to calculate and display the six-month moving average.
// It takes an array of sales as input.
void displaySixMonthMovingAverage(float sales[]) {
    // Print the header of the moving average report.
    printf("\nSix-Month Moving Average Report:\n");

    // Loop through the months, but stop 6 months before the end because we calculate 6-month averages.
    for (int i = 0; i <= NUM_MONTHS - 6; i++) {
        float total = 0;  // Initialize the total for the 6-month period.

        // Inner loop to sum the sales for the current 6-month period.
        for (int j = i; j < i + 6; j++) {
            total += sales[j];  // Add the current month's sales to the total.
        }

        // Print the moving average for the 6-month period.
        // months[i] represents the start month and months[i + 5] represents the end month.
        printf("%s-%s:\t%.2f\n", months[i], months[i + 5], total / 6);  // Calculate and print the average.
    }
}

// Function to display the sales sorted from highest to lowest.
// It takes an array of sales as input.
void displaySalesDescending(float sales[]) {
    // Declare arrays to hold the sorted sales and the corresponding month indexes.
    float sortedSales[NUM_MONTHS];  // Array to store sorted sales.
    int monthIndexes[NUM_MONTHS];   // Array to store the indexes of the months.

    // Copy the sales data to the sortedSales array and initialize the monthIndexes array.
    for (int i = 0; i < NUM_MONTHS; i++) {
        sortedSales[i] = sales[i];   // Copy each sales value to the sortedSales array.
        monthIndexes[i] = i;         // Store the original index of each month.
    }

    // Sort the sales in descending order using a simple bubble sort.
    // The bubble sort swaps both the sales values and the corresponding month indexes.
    for (int i = 0; i < NUM_MONTHS - 1; i++) {
        for (int j = 0; j < NUM_MONTHS - i - 1; j++) {
            if (sortedSales[j] < sortedSales[j + 1]) {  // If the current sales value is less than the next one...
                // Swap the sales amounts.
                float temp = sortedSales[j];
                sortedSales[j] = sortedSales[j + 1];
                sortedSales[j + 1] = temp;

                // Swap the corresponding month indexes.
                int tempIndex = monthIndexes[j];
                monthIndexes[j] = monthIndexes[j + 1];
                monthIndexes[j + 1] = tempIndex;
            }
        }
    }

    // Print the sorted sales report (highest to lowest).
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month\t\tSales\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        // Print the month and sales value.
        // months[monthIndexes[i]] gives the name of the month corresponding to the sorted sales.
        printf("%-10s\t%.2f\n", months[monthIndexes[i]], sortedSales[i]);
    }
}

int main() {
    float sales[NUM_MONTHS];  // Declare an array to store sales for each month
    FILE *file;  // Declare a file pointer for reading the file

    // Open the file for reading
    file = fopen("code1.txt", "r");
    if (file == NULL) {  // Check if the file was successfully opened
        printf("Error: Could not open file.\n");
        exit(1);  // Exit the program with an error code if the file could not be opened
    }

    // Read the sales data from the file
    for (int i = 0; i < NUM_MONTHS; i++) {
        fscanf(file, "%f", &sales[i]);  // Read each floating-point sales value from the file
    }

    // Close the file after reading
    fclose(file);

    // Call the functions to generate and display the various reports
    displayMonthlySalesReport(sales);           // Call the function to display the Monthly Sales Report
    displaySalesSummary(sales);                 // Call the function to display the Sales Summary Report
    displaySixMonthMovingAverage(sales);        // Call the function to display the Six-Month Moving Average Report
    displaySalesDescending(sales);              // Call the function to display the Sales Report (Highest to Lowest)

    return 0;  // Return 0 to indicate the program ended successfully
}