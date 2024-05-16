#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>

#include "menu.h"
#include "order.h"

class shop {
private:
	menu m;

	std::string phone;
	std::string address;
	double revenue = 0;

	// Number of orders
	int num_orders = 0;

	// Base address of order array (nullptr if array is empty)
	order* orders = nullptr;
public:
	/*
	 * Name: shop (default constructor) - required
	 * Description: Constructs a shop with a defaultly-constructed menu,
	 *		an empty phone number and address, 0 revenue, and no orders.
	 */
	shop();

	/*
	 * Name: add_coffee_to_menu - required
	 * Description: Adds a coffee to the shop's menu
	 * Parameters:
	 *		c (const coffee&): The coffee to add to the shop's menu
	 * Post conditions: Coffee added to menu
	 */
	void add_coffee_to_menu(const coffee& c);

	/*
	 * Name: add_order - required
	 * Description: Adds an order to the order array
	 * Parameters:
	 *		o (const order&): The order to add to the array
	 * Post conditions: Order added to array (array may need to be
	 *		reallocated, and num_orders should be incremented by 1)
	 */
	void add_order(const order& o);

	/*
 	* Name: populate_from_file
 	* Description: Sets phone and address from shop_info.txt
	* Parameters:
 	*		file(std::ifstream&): file to be read from
 	* Post-conditions: Phone and address are set
 	*/
	void populate_from_file(std::ifstream& file);
	
	/*
 	* Name: print_contact_info
 	* Description: Prints phone and address from shop_info.txt 
 	*/
	void print_contact_info() const;

	// Getter and setter for revenue
	/*
 	* Name: set_revenue
 	* Description: Sets revenue to given input
	* Parameters:
 	*		new_revenue(const double&): Given revenue to be copied 
 	* Post-conditions: Revenue is updated  
 	*/
	void set_revenue(const double& new_revenue);

	/*
 	* Name: get_revenue
 	* Description: Gets current revenue from shop
 	* Returns (double): Revenue from shop
 	*/
	double get_revenue() const;

	/*
 	* Name: get_menu
 	* Description: Allows other .cpp files to access menu attached to shop s
 	* Returns (menu&): Reference to menu attached to shop s
 	*/
	menu& get_menu();

	/*
 	* Name: get_menu
 	* Description: Allows other .cpp files to access menu attached to shop s
		(const version)
 	* Returns (const menu&): Constant reference to menu attached to shop s
 	*/
	const menu& get_menu() const;

	/*
 	* Name: set_num_orders
 	* Description: Sets num_orders from shop to updated value
	* Parameters:
 	*		new_orders(const double&): Updated value of num_orders 
				to be copied
 	* Post-conditions: num_orders is updated
 	*/
	void set_num_orders(const double& new_orders);

	/*
 	* Name: get_num_orders 
 	* Description: Gets current value of num_orders
 	* Returns (int): current value of num_orders
 	*/
	int get_num_orders() const;

	/*
 	* Name: print_orders
 	* Description: Prints all order information from array, 
			including order number, name, coffee size, and quantity
 	*/
	void print_orders() const;

	/*
 	* Name: print_order_file
 	* Description: Print all order information from array into an output file
			orders.txt
	* Parameters: 
 	*		file(std::ofstream&): file to be written to
 	* Post-conditions: File is written with current order array information
 	*/
	void print_order_file(std::ofstream& file);

	/*
 	* Name: total_cost
 	* Description: Determines total cost from a given order depending on
			its quantity and size from a given coffee determined by 
			order_option
	* Parameters:
 	*		quantity(int): quantity from the given order
			size(char): size of coffee from the given order
			order_option(int): coffee selected from user
 	* Returns (double): Total cost from given order
 	*/
	double total_cost(int quantity, char size, int order_option) const;

	/*
 	* Name: delete_coffee_from_menu
 	* Description: Deletes coffee from menu.txt and from coffee array
	* Parameters: 
 	*		index(const int&): index from coffee array for coffee 
				to be deleted
 	* Post-conditions: menu.txt is updated with new menu and coffee array 
		resized to fit fewer coffees
 	*/
	void delete_coffee_from_menu(const int& index);
	
	/*
 	* Name: shop
 	* Description: Destructor for orders array
 	* Post-conditions: Orders array is properly deleted
 	*/
	~shop();

	/*
 	* Name: shop
 	* Description: copy constructor for shop class and orders array
	* Parameters: 
 	*		s(const shop&): constant reference to given shop class
 	* Post-conditions: deep copy is peformed from shop classes, 
			including array
 	*/
	shop(const shop& s);

	/*
 	* Name: operator=
 	* Description: assignment operator overload for shop class 
			and orders array
	* Parameters:
 	*		s(const shop&): constant reference to given shop class
 	* Post-conditions: assignment operator defined for deep copies 
 	*/
	shop& operator=(const shop& s);
};

#endif
