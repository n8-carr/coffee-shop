#include <iostream>
#include <fstream>
#include "shop.h"

shop::shop() {} // Default constructor

void shop::add_coffee_to_menu(const coffee& c){
	// Adds coffee to array and updates menu.txt with new coffee
	get_menu().add_coffee(c);
	std::ofstream output_file("menu.txt");
	get_menu().print_array_file(output_file);
}

void shop::add_order(const order& o) {
	// New array made to fit extra order
	order* new_order_array = new order[this->num_orders + 1];
	// Copies over existing data of orders
	for (int i = 0; i < this->num_orders; i++) {
		new_order_array[i] = this->orders[i];
	}
	// Adds current order information into last slot on array
	new_order_array[this->num_orders] = o;
	// Deletes old orders array
	if (this->orders != nullptr) {
		delete [] orders;
	}
	// Sets orders pointer to new array, and num_orders incremented
	this->orders = new_order_array;
	this->num_orders++;
}

// Populates shop info and address from shop_info.txt
void shop::populate_from_file(std::ifstream& file){
	std::getline(file, this -> phone);
	std::getline(file, this -> address);
}

// Prints shop address and phone number
void shop::print_contact_info() const{
	std::cout << "Address: " << this->address<< std::endl;
	std::cout << "Phone: " << this->phone<< std::endl;
}

// Getter and setter for revenue, updated with new orders
void shop::set_revenue(const double& new_revenue){
	this->revenue = new_revenue;
}
double shop:: get_revenue() const {
	return revenue;
}

// Getter for menu
menu& shop::get_menu(){
	return m;
}

// Getter for menu, const version
const menu& shop::get_menu() const{
	return m;
}

// Getter and setter for num_orders
void shop::set_num_orders(const double& new_orders){
	this->num_orders = new_orders;
}
int shop::get_num_orders() const{
	return num_orders;
}

// Prints all information from orders array into terminal
void shop::print_orders() const{
	for (int i = 0; i < this->num_orders; i++) {
		this->orders[i].print_order_info();
		std::cout << std::endl;
	}
}

// Print all information from orders array into orders.txt
void shop::print_order_file(std::ofstream& file) {
	file << this->num_orders << std::endl;
	for (int i = 0; i < this->num_orders; i++) {
		file << orders[i].get_order_number() << " " 
			<< orders[i].get_coffee_name_order() << " " 
			<< orders[i].get_coffee_size() << " "
			<< orders[i].get_quantity() << std::endl;
	}
}

// Determines total cost from given order
double shop::total_cost (int quantity, char size, int order_option) const{
	double cost = 0;
	// Gets small size price from given option, and multiplies by quantity
	// for cost
	if (size == 'S') {
		double s_price = get_menu().sm_price(order_option - 1);
		cost = quantity * s_price;
	// Gets medium size price from given option, and multiplies by quantity
	// for cost
	} else if (size == 'M') {
		double m_price = get_menu().m_price(order_option - 1);
		cost = quantity * m_price;
	// Gets large size price from given option, and multiplies by quantity
	// for cost
	} else if (size == 'L') {
		double l_price = get_menu().lg_price(order_option - 1);
		cost = quantity * l_price;
	}
	return cost;
}

void shop::delete_coffee_from_menu (const int& index){
	get_menu().delete_coffee(index); // Deletes coffee from coffee array
	// Updates menu.txt with fewer options
	std::ofstream output_file("menu.txt");
	get_menu().print_array_file(output_file);
}

// Destructor
shop::~shop() {
	delete [] orders;
}

// Copy constructor
shop::shop(const shop& s) {
	// Copies all member variables information
	this->m = s.m; 
	this->phone = s.phone;
    this->address = s.address;
    this->revenue = s.revenue;
    this->num_orders = s.num_orders;

	// Copies orders array information
	if (num_orders > 0) {
		this->orders = new order[num_orders];
		for (int i = 0; i < num_orders; i++) {
			this->orders[i] = s.orders[i];
		}
	} else {
		this->orders = nullptr;
	}
}

// Assignment operator overload
shop& shop::operator=(const shop& s) {
	// Checks if copy of same object is attempted
	if (this == &s) {
		return *this;
	}

	// Copy constructor information
	this->m = s.m; 
	this->phone = s.phone;
    this->address = s.address;
    this->revenue = s.revenue;
    this->num_orders = s.num_orders;

	// Deletes previous orders array if present
	if (this->orders != NULL) {
		delete [] this->orders;
	}
	
	if (num_orders > 0) {
		this->orders = new order[num_orders];
		for (int i = 0; i < num_orders; i++) {
			this->orders[i] = s.orders[i];
		}
	} else {
		this->orders = nullptr;
	}
	return *this;
}
