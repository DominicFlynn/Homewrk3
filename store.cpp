
#include "store.h"
#include <sstream>
#include <string>

// Constructor
Store::Store()
    : num_customers_(0),
      num_products_(0),
      num_transactions_(0)
{
}

// Set and get customer count
void Store::num_customers(int customer_count)
{
    if (customer_count >= 0 && customer_count <= 100)
        num_customers_ = customer_count;
}

int Store::num_customers()
{
    return num_customers_;
}

// Set and get product count
void Store::num_products(int product_count)
{
    if (product_count >= 0 && product_count <= 100)
        num_products_ = product_count;
}

int Store::num_products()
{
    return num_products_;
}

// Set and get transaction count
void Store::num_transactions(int transaction_count)
{
    if (transaction_count >= 0 && transaction_count <= 100)
        num_transactions_ = transaction_count;
}

int Store::num_transactions()
{
    return num_transactions_;
}

// Add a customer
bool Store::add_customer(Person customer)
{
    if (num_customers_ >= 100)
        return false;

    if (find_customer(customer) != -1)
        return false;

    customers_[num_customers_] = customer;
    num_customers_++;

    return true;
}

// Update a customer
bool Store::update_customer(int index, Person customer)
{
    if (index < 0 || index >= num_customers_)
        return false;

    customers_[index] = customer;
    return true;
}

// Get a customer
Person Store::get_customer(int index)
{
    if (index < 0 || index >= num_customers_)
        return Person();

    return customers_[index];
}

// Add a product
bool Store::add_product(product item)
{
    if (num_products_ >= 100)
        return false;

    for (int i = 0; i < num_products_; i++)
    {
        if (products_[i].name == item.name)
            return false;
    }

    products_[num_products_] = item;
    num_products_++;

    return true;
}

// Get a product
product Store::get_product(int index)
{
    if (index < 0 || index >= num_products_)
        return product();

    return products_[index];
}

// Add a transaction
bool Store::add_transaction(transaction new_transaction)
{
    if (num_transactions_ >= 100)
        return false;

    new_transaction.transaction_number = num_transactions_ + 1;
    transactions_[num_transactions_] = new_transaction;
    num_transactions_++;

    return true;
}

// Get a transaction
transaction Store::get_transaction(int index)
{
    if (index < 0 || index >= num_transactions_)
        return transaction();

    return transactions_[index];
}

// Find a customer by name
int Store::find_customer(Person cust)
{
    for (int i = 0; i < num_customers_; i++)
    {
        if (customers_[i].name() == cust.name())
            return i;
    }

    return -1;
}

// Make a purchase
bool Store::make_purchase(Person customer, product item, int quantity)
{
    if (quantity <= 0)
        return false;

    int customer_index = find_customer(customer);

    if (customer_index == -1)
        return false;

    int product_index = -1;

    for (int i = 0; i < num_products_; i++)
    {
        if (products_[i].name == item.name)
        {
            product_index = i;
            break;
        }
    }

    if (product_index == -1)
        return false;

    if (num_transactions_ >= 100)
        return false;

    Person stored_customer = customers_[customer_index];
    product stored_product = products_[product_index];

    double total = stored_product.price * quantity;

    credit_card card = stored_customer.person_credit_card();

    if (!card.make_purchase(total))
        return false;

    stored_customer.person_credit_card(card);

    transaction new_transaction;
    new_transaction.transaction_number = num_transactions_ + 1;
    new_transaction.customer = stored_customer;
    new_transaction.purchased_item = stored_product;
    new_transaction.quantity = quantity;

    // Save the updated customer and record the purchase.
    customers_[customer_index] = stored_customer;
    transactions_[num_transactions_] = new_transaction;
    num_transactions_++;

    return true;
}

// Display all products
std::string Store::product_info()
{
    std::ostringstream output;

    for (int i = 0; i < num_products_; i++)
    {
        output << products_[i].product_info() << "\n";
    }

    return output.str();
}

// Display all transactions
std::string Store::transaction_info()
{
    std::ostringstream output;

    for (int i = 0; i < num_transactions_; i++)
    {
        output << transactions_[i].transaction_info() << "\n";
    }

    return output.str();
}

// Display all customers
std::string Store::customer_info()
{
    std::ostringstream output;

    for (int i = 0; i < num_customers_; i++)
    {
        output << customers_[i].person_info() << "\n";
    }

    return output.str();
}

// Display purchase history for one customer
std::string Store::purchase_history(Person customer)
{
    std::ostringstream output;
    bool found = false;

    for (int i = 0; i < num_transactions_; i++)
    {
        if (transactions_[i].customer.name() == customer.name())
        {
            output << transactions_[i].transaction_info() << "\n";
            found = true;
        }
    }

    if (!found)
        output << "No purchases found.\n";

    return output.str();
}

// Display complete store information
std::string Store::store_info()
{
    std::ostringstream output;

    output << "Number of customers: "
           << num_customers_ << "\n";

    output << "Number of products: "
           << num_products_ << "\n";

    output << "Number of transactions: "
           << num_transactions_ << "\n\n";

    output << "CUSTOMERS\n";
    output << customer_info() << "\n";

    output << "PRODUCTS\n";
    output << product_info() << "\n";

    output << "TRANSACTIONS\n";
    output << transaction_info();

    return output.str();
}

