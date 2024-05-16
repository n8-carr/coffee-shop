#ifndef MENU_H
#define MENU_H

#include "coffee.h"
#include <fstream>
#include <iostream>

class menu {
private:
	// Number of coffees in menu
	int num_coffees = 0;

	// Base address of coffee array (nullptr if array is empty)
	coffee* coffees = nullptr;
public:
	/*
	 * Name: menu (default constructor) - required
	 * Description: Constructs a menu with an empty coffee array
	 */
	menu();

	/*
	 * Name: add_coffee - required
	 * Description: Adds a coffee to the coffee array
	 * Parameters:
	 *		c (const coffee&): The coffee to add to the array
	 * Post conditions: Coffee added to array (array may need to be
	 *		reallocated, and num_coffees should be incremented by 1)
	 */
	void add_coffee(const coffee& c);

	/*
 	* Name: make_coffee_menu
 	* Description: creates coffee array and fills with data from given file
	* Parameters:
 	*		file(std::ifstream&): file with coffee information, menu.txt
 	* Post-conditions: coffee array made and filled with coffee data
 	*/
	void make_coffee_menu(std::ifstream& file);

	/*
 	* Name: print_menu
 	* Description: calls on make_coffee_menu and prints to terminal coffee
			info in different ways based on option selected
	* Parameters:
 	*		file(std::ifstream&): input file with coffee info, menu.txt
			option(const int&): constant reference of option selected by user 
 	*/
	void print_menu(std::ifstream& file, const int& option);

	/*
 	* Name: print_array_file
 	* Description: prints coffee info from array into menu.txt, updating 
			with as new coffee objects are made/deleted
	* Parameters:
 	*		file(std::ofstream&): output file to write coffee info, menu.txt
 	* Post-conditions: menu.txt updated to reflect current coffee array
 	*/
	void print_array_file(std::ofstream& file) const;

	/*
 	* Name: set_num_coffees
 	* Description: sets num_coffess to updated value
	* Parameters:
 	*		new_num(int): new value of num_coffees to be set
 	* Post-conditions: num_coffees updated
 	*/
	void set_num_coffees(int new_num);

	/*
 	* Name: get_num_coffees
 	* Description: gets current value of num_coffees
 	*/
	int get_num_coffees() const;
	
	/*
 	* Name: coffee_name
 	* Description: gets the name of specific a coffee with a given index
	* Parameters:
 	*		index(const int&): index of coffee
 	* Returns (std::string): name of coffee from coffee array
 	*/
	std::string coffee_name (const int& index) const;

	/*
 	* Name: sm_price
 	* Description: gets the price of small size of coffee with given index
	* Parameters:
 	*		index(const int&): index of coffee
 	* Returns (double): price of small size
 	*/
	double sm_price (const int& index) const;

	/*
 	* Name: m_price
 	* Description: gets the price of medium size of coffee with given index
	* Parameters:
 	*		index(const int&): index of coffee
 	* Returns (double): price of medium size
 	*/
	double m_price (const int& index) const;

	/*
 	* Name: lg_price
 	* Description: gets the price of large size of coffee with given index
	* Parameters:
 	*		index(const int&): index of coffee
 	* Returns (double): price of large size
 	*/
	double lg_price (const int& index) const;
	
	/*
 	* Name: print_coffee_name_search
 	* Description: prints coffee info from given name to terminal,
			if avaliable
	* Parameters:
 	*		user_name(const std::string&): name of coffee for search
 	*/
	void print_coffee_name_search(const std::string& user_name) const;

	/*
 	* Name: print_coffee_budget_search
 	* Description: prints coffees and their sizes that are below a
			given budget
	* Parameters:
 	*		budget(consst double&): budget of user for search
 	*/
	void print_coffee_budget_search(const double& budget) const;

	/*
 	* Name: print_coffee
 	* Description: prints coffee information at a given index from array
	* Parameters:
 	*		index(const int&): index of coffee to be printed
 	*/
	void print_coffee(const int& index) const;
	
	/*
 	* Name: delete_coffee
 	* Description: deletes coffee from coffee array and resizes array, 
			while updating num_coffees
	* Parameters:
 	*		index(const int&): index of coffee to be deleted
 	* Post-conditions: array resized to fewer items
 	*/
	void delete_coffee(const int& index);

	/*
 	* Name: menu
 	* Description: destructor for coffees array
	* Post-conditons: coffees array deleted
 	*/
	~menu();

	/*
 	* Name: menu
 	* Description: copy constructor for menu class and coffees array
	* Parameters: 
 	*		m(const menu&): constant reference to given menu class
 	* Post-conditions: deep copy is peformed from menu classes, 
			including array
 	*/
	menu(const menu& m);

	/*
 	* Name: operator=
 	* Description: assignment operator overload for menu class 
			and coffees array
	* Parameters:
 	*		m(const menu&): constant reference to given menu class
 	* Post-conditions: assignment operator defined for deep copies
 	*/
	menu& operator=(const menu& m);
};

#endif
