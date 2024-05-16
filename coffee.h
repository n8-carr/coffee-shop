#ifndef COFFEE_H
#define COFFEE_H

#include <string>
#include <fstream>
#include <iostream>

class coffee {
private:
	std::string name;
	double small_cost = 0.0;
	double medium_cost = 0.0;
	double large_cost = 0.0;

public:
	/*
	 * Name: coffee (default constructor) - required
	 * Description: Constructs a coffee object with an empty name
	 *		and all costs of 0
	 */
	coffee();

	/*
 	* Name: coffee
 	* Description: non-default constructor for coffee objects
	* Parameters:
 	*		name(const std::string& name): name of coffee object
			sm_price(double): small coffee price
			m_price(double): medium coffee price
			lg_price(double) large coffee price
 	* Returns (coffee): constructed coffee object
 	*/
	coffee(const std::string& name, double sm_price, double m_price, 
			double lg_price);

	/*
 	* Name: set_coffee_info
 	* Description: sets coffee information from menu.txt
	* Parameters:
 	*		file(std::ifstream& file): menu.txt
 	* Post-conditons: coffee info set
 	*/
	void set_coffee_info(std::ifstream& file);

	/*
 	* Name: 
 	* Description: print_coffee_info
	* Parameters: prints coffee info to terminal
 	*/
	void print_coffee_info() const;

	/*
 	* Name: get_name
 	* Description: getter for coffee name
 	* Returns (std::string): coffee name
 	*/
	std::string get_name() const;

	/*
 	* Name: get_sm_price
 	* Description: getter for small price of coffee 
 	* Returns (double): small price
 	*/
	double get_sm_price() const;

	/*
 	* Name: get_m_price
 	* Description: getter for medium price of coffee
 	* Returns (double): medium price
 	*/
	double get_m_price() const;

	/*
 	* Name: get_lg_price
 	* Description: getter for large price of coffee
 	* Returns (double): large price
 	*/
	double get_lg_price() const;
};

#endif
