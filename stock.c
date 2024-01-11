#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100  // Assuming a maximum of 100 products

// Product structure (already defined in the previous response)
// ...

// Function prototypes for StockManager functions (implementations to be added)
void addProduct(Product** products, int* numProducts, const char* name, double price, int quantity);
void displayStock(Product* products, int numProducts);
void updateStock(Product* products, int numProducts, const char* productName);

int main() {
    Product* products[MAX_PRODUCTS];
    int numProducts = 0;

    int choice;

    while (1) {
        // Clear screen functionality can be implemented using system-specific calls or libraries

        // Display menu options
        printf("Options:\n");
        printf("1. Add Product\n");
        printf("2. Update Stock\n");
        printf("3. Display Stock\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Get product details from user and call addProduct
                char name[50];
                double price;
                int quantity;
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product price: ");
                scanf("%lf", &price);
                printf("Enter initial quantity: ");
                scanf("%d", &quantity);
                addProduct(products, &numProducts, name, price, quantity);
                break;
            case 2:
                displayStock(products, numProducts);
                // Get product name to update and call updateStock
                char productName[50];
                printf("Enter product name to update stock: ");
                scanf("%s", productName);
                updateStock(products, numProducts, productName);
                break;
            case 3:
                displayStock(products, numProducts);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

// Implementing the remaining functions: addProduct, displayStock, updateStock, and clearScreen
void addProduct(Product** products, int* numProducts, const char* name, double price, int quantity) {
    if (*numProducts >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    Product* product = createProduct(name, price, quantity);
    if (product == NULL) {
        printf("Error allocating memory for product.\n");
        return;
    }

    products[*numProducts] = product;
    (*numProducts)++;
}

void displayStock(Product* products, int numProducts) {
    printf("\nStock List:\n");
    printf("------------\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d. %s (Price: %.2lf, Quantity: %d)\n", i + 1, getName(products[i]), getPrice(products[i]), getQuantity(products[i]));
    }
    printf("------------\n");
}

void updateStock(Product* products, int numProducts, const char* productName) {
    int found = 0;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(getName(products[i]), productName) == 0) {
            found = 1;
            int newQuantity;
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            setQuantity(products[i], newQuantity);
            printf("Stock updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }
}

void clearScreen() {
    #ifdef _WIN32
    system("cls");  // Windows-specific clear screen
    #else
    system("clear");  // Unix-like systems clear screen
    #endif
}

