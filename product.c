#include <stdio.h>
#include <string.h>

typedef struct Product {
    char name[50];  // Assuming a maximum name length of 50 characters
    double price;
    int quantity;
} Product;

// Constructor-like function to create a Product struct
Product* createProduct(const char* name, double price, int quantity) {
    Product* product = (Product*)malloc(sizeof(Product));  // Allocate memory
    if (product == NULL) {
        return NULL;  // Handle memory allocation failure
    }
    strcpy(product->name, name);
    product->price = price;
    product->quantity = quantity;
    return product;
}

// Getter functions
const char* getName(Product* product) {
    return product->name;
}

double getPrice(Product* product) {
    return product->price;
}

int getQuantity(Product* product) {
    return product->quantity;
}

// Setter function
void setQuantity(Product* product, int quantity) {
    product->quantity = quantity;
}

// Free the allocated memory for a Product struct
void freeProduct(Product* product) {
    free(product);
}
