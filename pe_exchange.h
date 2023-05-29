#ifndef PE_EXCHANGE_H
#define PE_EXCHANGE_H

#include "pe_common.h"

// Constants
#define MAX_TRADERS 10
#define MAX_COMPONENTS 100
#define TRANSACTION_FEE_PERCENTAGE 1

// Structures
typedef struct {
    char trader_name[MAX_TRADER_NAME_LENGTH];
    int balance;
    int component_count;
} Trader;

typedef struct {
    char component[MAX_COMPONENT_LENGTH];
    int quantity;
} ComponentListing;

typedef struct {
    int transaction_id;
    char buyer[MAX_TRADER_NAME_LENGTH];
    char seller[MAX_TRADER_NAME_LENGTH];
    char component[MAX_COMPONENT_LENGTH];
    int quantity;
    int price;
} Transaction;

// Function prototypes
void initialize_exchange();
void process_order(Order* order);
void match_orders();
void execute_transaction(Order* buy_order, Order* sell_order);
void update_trader_balances(Order* buy_order, Order* sell_order, int transaction_price);
void update_component_listing(Order* order);
void update_transaction_history(Order* buy_order, Order* sell_order, int transaction_price);
void handle_error(Order* order, const char* error_message);

#endif /* PE_EXCHANGE_H */