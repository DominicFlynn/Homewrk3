#include "transaction.h"
#include <sstream>

std::string transaction::transaction_info()
{
    std::ostringstream output;

    output << "Transaction Number: " << transaction_number << "\n";
    output << "Customer: " << customer.name() << "\n";
    output << "Product: " << purchased_item.name << "\n";
    output << "Quantity: " << quantity << "\n";
    output << "Total: $" << purchased_item.price * quantity << "\n";

    return output.str();
}
