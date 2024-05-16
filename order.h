#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>

class order {
private:
	int order_number = 0;
	std::string coffee_name;
	char coffee_size = 0;
	int quantity = 0;
public:
	/* 
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `order.cpp` OR SET IT TO `default`.
	 *		THIS FUNCTION IS USED BY THE BIG 3 TESTING SCRIPT.
	 * Name: order (default constructor)
	 * Description: Constructs an order with order_number 0,
	 *		empty coffee name, null (0) coffee size, and 0
	 *		quantity.
	 */
	order();

	/*
 	* Name: order
 	* Description: non-default constructor for orders
	* Parameters:
 	*		order_number(int): number of the order
			coffee_name(std::string): name of coffee for the order
			coffee_size(char): size of coffee for the order
			quantity(int): quantity of coffees for the order
 	* Returns (order): initilized order with member variables set
 	*/
	order(int order_number, std::string coffee_name, char coffee_size, 
		int quantity);

	/*
 	* Name: print_order_info
 	* Description: prints order information to terminal
 	*/
	void print_order_info() const;
	
	/*
 	* Name: get_order_number
 	* Description: gets order number of order object
 	* Returns (int): order number
 	*/
	int get_order_number() const;

	/*
 	* Name: get_coffee_name_order
 	* Description: gets coffee name of order object
 	* Returns (std::string): name of coffee of order
 	*/
	std::string get_coffee_name_order() const;

	/*
 	* Name: get_coffee_size
 	* Description: gets coffee size of order object
 	* Returns (char): coffee size of order
 	*/
	char get_coffee_size() const;

	/*
 	* Name: get_quantity
 	* Description: gets quantity of coffees from order
 	* Returns (int): quantity of coffees 
 	*/
	int get_quantity() const;
};

#endif
