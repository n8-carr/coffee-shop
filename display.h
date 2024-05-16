#ifndef DISPLAY_H
#define DISPLAY_H

#include "shop.h"

/*
 * Name: get_option - suggested
 * Description: Prompt the user for their numbered option selection
 * Returns (int): The number associated with the option selected by the user
 */
int get_option();

/*
 * Name: execute_option - suggested
 * Description: Execute the option selected by the user
 * parameters:
 *		s (shop&): A reference to the shop object
 *		option (int): The user's selected option to execute. Must be
 *			between 1 and 7 (inclusive).
 */
void execute_option(shop& s, int& option);

/*
 * Name: get_coffee_name
 * Description: saves coffee name provided by user 
 * Returns (std::string): coffee name provided by user
 */
std::string get_coffee_name();

/*
 * Name: get_coffee_prices
 * Description: Ensures that coffee prices given by user are positive
 * Parameters:
 *		sm_price(double&): price for small user coffee
        m_price(double&): price for medium user coffee
        lg_price(double&): price for large user coffee
    Post conditions: All prices are valid, meaning positive
 */
void get_coffee_prices(double& sm_price, double& m_price, double& lg_price);

/*
 * Name: positive_checker
 * Description: Checks whether number provided is positive
 * Parameters:
 *		input(const double&): number to be checked
 * Returns (bool): true if number is positive, vice versa
 */
bool positive_checker(const double& input);

/*
 * Name: file_open_check
 * Description: 
 * Parameters:
 		file(std::ifstream&): file to be opened
        option(int&): option to be modified for false 
 * Returns (bool): true if file could be opened, vice versa
 * Post-conditions: Option is set to 7 if found false
 */
bool file_open_check(std::ifstream& file, int& option);

/*
 * Name: get_coffee_selection
 * Description: Asks user for their coffee selection, and ensures its valid
 * Parameters:
 *		selection(int&): selected coffee number 
        option(): option program is running on
        num_coffees(int): number of coffees from the menu
 * Post-conditions: a valid selection is set
 */
void get_coffee_selection (int& selection, const int& option, int num_coffees);

/*
 * Name: get_coffee_size
 * Description: Prompts user for coffee size for orders, ensures its valid
 * Parameters:
 *		size(char&): size to be set in program
 * Post-conditions: a valid coffee size is set
 */
void get_coffee_size(char& size);

#endif
