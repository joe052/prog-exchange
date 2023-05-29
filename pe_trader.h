#ifndef PE_TRADER_H
#define PE_TRADER_H

#include "pe_common.h"

// Constants
#define MAX_TRADER_NAME_LENGTH 16

// Function prototypes
void process_command(const char* command);
void send_order_to_exchange(Order* order);
void receive_response_from_exchange();
void handle_error(const char* error_message);

#endif /* PE_TRADER_H */
