#ifndef PE_COMMON_H
#define PE_COMMON_H

// Constants
#define MAX_PRODUCT_LENGTH 16
#define MAX_ORDER_ID 999999
#define MAX_QUANTITY 999999
#define MAX_PRICE 999999

// Structures
typedef struct {
    int order_id;
    char product[MAX_PRODUCT_LENGTH];
    int quantity;
    int price;
} Order;

// Function prototypes
void parse_command(char* command, Order* order);

#endif /* PE_COMMON_H */
