#include "pe_trader.h"
#include <stdio.h>
#include <string.h>

// Function to process a trader command
void process_command(const char* command) {
    Order order;
    memset(&order, 0, sizeof(Order));
    parse_command(command, &order);

    if (order.order_id < 0 || order.order_id > MAX_ORDER_ID) {
        handle_error("Invalid order ID.");
        return;
    }

    // Send the order to the exchange
    send_order_to_exchange(&order);

    // Receive response from the exchange
    receive_response_from_exchange();
}

// Function to send an order to the exchange
void send_order_to_exchange(Order* order) {
    // Open the named pipe (FIFO) for writing
    FILE* fifo = fopen("exchange_fifo", "w");
    if (fifo == NULL) {
        handle_error("Failed to open the FIFO for writing.");
        return;
    }

    // Write the order to the FIFO
    fprintf(fifo, "%s %d %s %d %d;\n", order->action, order->order_id, order->product, order->quantity, order->price);

    // Close the FIFO
    fclose(fifo);
}

// Function to receive the response from the exchange
void receive_response_from_exchange() {
    // Open the named pipe (FIFO) for reading
    FILE* fifo = fopen("trader_fifo", "r");
    if (fifo == NULL) {
        handle_error("Failed to open the FIFO for reading.");
        return;
    }

    // Read the response from the FIFO
    char response[256];
    fgets(response, sizeof(response), fifo);

    // Close the FIFO
    fclose(fifo);

    // Display the response to the trader
    printf("Response from the exchange: %s\n", response);
}

// Function to handle errors and display appropriate error messages
void handle_error(const char* error_message) {
    fprintf(stderr, "Error: %s\n", error_message);
}
