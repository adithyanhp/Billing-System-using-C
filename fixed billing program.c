#include <stdio.h>

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

// Pass shop as a parameter to the functions
void printHeading(struct shop shop) {
  printf("\n\t*************************************\n");
  printf("\t*** Welcome to %s Shopping Center ***\n", shop.name);
  printf("\t*************************************\n");
}

// Pass customer as a parameter to the functions
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
  printf("\nGST (18%%): Rs. %.2f", gst); // Corrected the format specifier
  printf("\nTotal Amount: Rs. %.2f", totalAmount);
}

// Pass customer, shop, and items as parameters to the function
void printBill(struct customer customer, struct shop shop, struct item items[], int nItems) {
  printHeading(shop);
  printCustomerDetails(customer);
  printItemDetails(items, nItems);
}

int main() {
  struct customer customer;
  struct shop shop;
  struct item items[100];

  // Get customer details
  printf("\nEnter Customer Name: ");
  scanf("%s", customer.name);

  printf("\nEnter Customer Phone: ");
  scanf("%s", customer.phone);

  // Get shop details
  printf("\n\nEnter Shop Name: ");
  scanf("%s", shop.name);

  printf("\nEnter Shop Address: ");
  scanf("%s", shop.address);

  printf("\nEnter Shop City: ");
  scanf("%s", shop.city);

  printf("\nEnter Shop State: ");
  scanf("%s", shop.state);

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
