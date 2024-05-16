#include "order.h"

// TODO Implement the order class's member functions here

order::order() {}

order::order(int order_number, std::string coffee_name, char coffee_size, 
		int quantity) : order_number(order_number), coffee_name(coffee_name),
        coffee_size(coffee_size), quantity(quantity){}

void order::print_order_info() const{
    std::cout << "Order number: " << this->order_number << std::endl;
    std::cout << "Coffee: " << this->coffee_name << std::endl;
    std::cout << "Size: " << this->coffee_size << std::endl;
    std::cout << "Quantity: " << this->quantity << std::endl;
}

int order::get_order_number() const{
    return this->order_number;
}

std::string order::get_coffee_name_order() const{
    return this->coffee_name;
}

char order::get_coffee_size() const{
    return this->coffee_size;
}

int order::get_quantity() const{
    return this->quantity;
}
