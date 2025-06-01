#include <stdio.h>
#include <string.h>  // for removing newline

struct item {
    char name[50];
    int price;
    int quantity;
    float total;
};

struct customer {
    char name[50];
    char phone[20];
};

struct shop {
    char name[50];
    char address[100];
    char city[50];
    char state[50];
};

void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';  // remove newline if present
}

void printHeading(struct shop shop);
void printCustomerDetails(struct customer customer);
void printItemDetails(struct item items[], int nItems);
void printBill(struct customer customer, struct shop shop, struct item items[], int nItems);

int main() {
    struct customer customer;
    struct shop shop;
    struct item items[100];

    // Get customer details
    printf("\nEnter Customer Name: ");
    fgets(customer.name, sizeof(customer.name), stdin);
    removeNewline(customer.name);

    printf("\nEnter Customer Phone: ");
    fgets(customer.phone, sizeof(customer.phone), stdin);
    removeNewline(customer.phone);

    // Get shop details
    printf("\n\nEnter Shop Name: ");
    fgets(shop.name, sizeof(shop.name), stdin);
    removeNewline(shop.name);

    printf("\nEnter Shop Address: ");
    fgets(shop.address, sizeof(shop.address), stdin);
    removeNewline(shop.address);

    printf("\nEnter Shop City: ");
    fgets(shop.city, sizeof(shop.city), stdin);
    removeNewline(shop.city);

    printf("\nEnter Shop State: ");
    fgets(shop.state, sizeof(shop.state), stdin);
    removeNewline(shop.state);

    // Get item details
    int nItems = 0;
    char choice;

    do {
        printf("\nEnter Item Name: ");
        scanf("%s", items[nItems].name);

        printf("\nEnter Item Price: ");
        scanf("%d", &items[nItems].price);

        printf("\nEnter Quantity: ");
        scanf("%d", &items[nItems].quantity);

        items[nItems].total = items[nItems].price * items[nItems].quantity;

        nItems++;

        printf("\nDo you want to add another item? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    // Print the bill
    printBill(customer, shop, items, nItems);

    return 0;
}

void printHeading(struct shop shop) {
    printf("\n\t*************************************\n");
    printf("\t*** Welcome to %s Shopping Center ***\n", shop.name);
    printf("\tAddress: %s, %s, %s\n", shop.address, shop.city, shop.state);
    printf("\t*************************************\n");
}

void printCustomerDetails(struct customer customer) {
    printf("\nCustomer Name: %s", customer.name);
    printf("\nCustomer Phone: %s", customer.phone);
    printf("\n---------------------------------------\n");
}

void printItemDetails(struct item items[], int nItems) {
    int i;
    float subtotal = 0.0;

    for (i = 0; i < nItems; i++) {
        printf("\nItem Name: %s", items[i].name);
        printf("\nItem Price: Rs. %d", items[i].price);
        printf("\nQuantity: %d", items[i].quantity);
        printf("\nTotal: Rs. %.2f", items[i].total);

        subtotal += items[i].total;

        printf("\n---------------------------------------\n");
    }

    float gst = 0.18 * subtotal;
    float totalAmount = subtotal + gst;

    printf("\nSubtotal: Rs. %.2f", subtotal);
    printf("\nGST (18%%): Rs. %.2f", gst);
    printf("\nTotal Amount: Rs. %.2f", totalAmount);
}

void printBill(struct customer customer, struct shop shop, struct item items[], int nItems) {
    printHeading(shop);
    printCustomerDetails(customer);
    printItemDetails(items, nItems);
}
