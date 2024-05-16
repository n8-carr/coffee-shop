#include <iostream>
#include <string>
#include <fstream>
#include "display.h"
#include "coffee.h"
#include "order.h"

/*
 * Name: print_options() - suggested
 * Description: Print options to the user
 */
void print_options() {
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "	1. View shop info" << std::endl;
	std::cout << "	2. Add an item to menu" << std::endl;
	std::cout << "	3. Remove an item from menu" << std::endl;
	std::cout << "	4. Search by coffee name" << std::endl;
	std::cout << "	5. Search by price" << std::endl;
	std::cout << "	6. Place an order" << std::endl;
	std::cout << "	7. Log out" << std::endl;
}

/*
 * Name: print_selection_error - suggested
 * Description: Scolds the user for selecting a bad option
 *		number
 */
void print_selection_error() {
	std::cout << "Error: You must choose one of the 7 options provided"
		<< std::endl;
}

// Gets option from user, making sure it's valid
int get_option() {
	int option;
	bool first = true;
	do {
		if (!first) { // Prints error message if option is out of bounds
			print_selection_error();
		}
		first = false; 
		print_options();
		std::cout << "Selection: ";
		std::cin >> option;
		std::cout << std::endl;
	} while (option < 1 || option > 7);

	return option;
}

// Getter for coffee_name
std::string get_coffee_name() {
	std::string coffee_name;
	std::getline (std::cin, coffee_name);
	std::cout << std::endl;
	return coffee_name;
}

// Checks if numbers are positive
bool positive_checker(const double& input) {
	bool positive = false;
	if (input < 0) {
		positive = false;
		std::cout << "Enter a valid number/option!" << std::endl;
	} else {
		positive = true;
	}
	return positive;
}

// Getter and validator for coffee_prices
void get_coffee_prices(double& sm_price, double& m_price, double& lg_price) {
	bool valid = false;
	// Check for small size price input
	do {
		std::cout << "Enter price of small size (8oz): ";
		std::cin >> sm_price;
		if (positive_checker(sm_price) == false) {
			std::cout << std::endl;
		} else {
			valid = true;
			std::cout << std::endl;
		}
	} while (!valid);

	// Check for medium size price input
	do {
		std::cout << "Enter price of medium size (12oz): ";
		std::cin >> m_price;
		if (positive_checker(m_price) == false) {
			valid = false;
			std::cout << std::endl;
		} else {
			valid = true;
			std::cout << std::endl;
		}
	} while (!valid);

	// Check for large size price input
	do {
		std::cout << "Enter price of large size (16oz): ";
		std::cin >> lg_price;
		if (positive_checker(lg_price) == false) {
			valid = false;
			std::cout << std::endl;
		} else {
			valid = true;
			std::cout << std::endl;
		}
	} while (!valid);
}

// Checks if files can be opened
bool file_open_check(std::ifstream& file, int& option) {
	bool valid = false;
	if (file.fail()) {
		std::cout << "Menu info file failed to open!" << std::endl;
		option = 7; // Set option to 7, meaning main will close
	} else {
		valid = true;
	}
	return valid;
}

void get_coffee_selection (int& selection, const int& option, int num_coffees){
	bool pos_check = false;
	// Repeats until valid coffee selection is given
	do {
		// Prompt for option 3
		if (option == 3) {
			std::cout << "Which of the drinks above from our menu would " <<
			"you like to remove?" << std::endl;
		// Prompt for option 6
		} else if (option == 6) {
			std::cout << "Which of the drinks above from our menu would " <<
			"you like to order?" << std::endl;
		}
		std::cout << "Enter 1 - " << num_coffees << " : ";
		std::cin >> selection;
		// Check if selection provided is positive
		pos_check = positive_checker(selection);

		// Formating for case of invalid input
		if (!pos_check) {
			std::cout << std::endl;
		}
		if (selection > num_coffees || selection == 0) {
			std::cout << "Enter a valid number/option!" << std::endl;
			std::cout << std::endl;
		}
	} while (!pos_check || selection > num_coffees || selection == 0);
}

// Validates coffee size provided by user
void get_coffee_size(char& size) {
	// Repeats until valid size is given
	do {
		std::cout << "Enter the size: S-Small, M-Medium, L-Large: ";
		std::cin >> size;
		if (size != 'S' && size != 'M' && size != 'L') {
			std::cout << "Enter a valid size!" << std::endl;
			std::cout << std::endl;
		}
	} while (size != 'S' && size != 'M' && size != 'L');
}

// Main body of display
void execute_option(shop& s, int& option) {
	if (option == 1) {
		// Print shop info and revenue
		s.print_contact_info();
		std::cout << "The shop revenue is: $" << s.get_revenue() << std::endl;
		
		// Print menu from file
		std::cout << "Here is our menu:" << std::endl << std::endl;
		std::ifstream menu_file;
		menu_file.open("menu.txt");

		// Checks if menu.txt could be opened, and prints if true
		if (file_open_check(menu_file, option) == false) {
			return;
		}
		s.get_menu().print_menu(menu_file, option);

		// Print orders
		std::cout << "Order info:" << std::endl;
		// Runs when no orders are present
		if (s.get_num_orders() == 0) {
			std::cout << "No orders to display!" << std::endl << std::endl;
		} else {
			s.print_orders();
		}
	} else if (option == 2) {
		// Create menu from menu.txt and check if it can be opened
		std::ifstream menu_file;
		menu_file.open("menu.txt");
		if (file_open_check(menu_file, option) == false) {
			return;
		} // Once opened, coffee array is made
		s.get_menu().make_coffee_menu(menu_file);
		
		// Get coffee name, assuming valid entry
		std::cout << "Enter the name of the new coffee drink (in 1 word): ";
		std::string coffee_name = get_coffee_name();

		// Get prices and validate correct inputs
		double sm_price, m_price, lg_price;
		get_coffee_prices(sm_price, m_price, lg_price);

		// Make coffee item to add to array
		coffee user_coffee(coffee_name, sm_price, m_price, lg_price);

		// Adds user coffee to end of bigger dynamic array
		s.add_coffee_to_menu(user_coffee);
		std::cout << "This new drink has been successfully" <<
			" added to the coffee menu!" << std::endl << std::endl;
	} else if (option == 3) {
		// Create menu from menu.txt and check if it can be opened
		std::ifstream menu_file;
		menu_file.open("menu.txt");
		if (file_open_check(menu_file, option) == false) {
			return;
		}
		s.get_menu().print_menu(menu_file, option);
		
		int index = 0; // Index for coffee removal
		// Checks if index provided by user is valid, and repeats till valid
		get_coffee_selection(index, option, s.get_menu().get_num_coffees());
		std::cout << std::endl;

		// Deletes coffee from coffee array, shrinking the array
		s.delete_coffee_from_menu(index);
		std::cout << "This drink has been successfully removed from the menu!"
			<< std::endl << std::endl;
	} else if (option == 4) {
		// Create menu from menu.txt and checks if it can be opened
		std::ifstream menu_file;
		menu_file.open("menu.txt");
		if (file_open_check(menu_file, option) == false) {
			return;
		}
		s.get_menu().make_coffee_menu(menu_file);

		// Asks user for coffee and assumes valid
		std::cout << "Enter the coffee name: ";
		std::string coffee_search = get_coffee_name();
		// Prints coffee info based on given name
		s.get_menu().print_coffee_name_search(coffee_search);
	} else if (option == 5) {
		// Create menu from menu.txt and checks if it can be opened
		std::ifstream menu_file;
		menu_file.open("menu.txt");
		if (file_open_check(menu_file, option) == false) {
			return;
		}
		s.get_menu().make_coffee_menu(menu_file);
		double budget = 0; // Budget variable for user input
		
		// Repeats untill valid budget is given (positive)
		do {
			std::cout << "Enter your budget for one drink, and I will list" 
			<< std::endl << "out our products that are cheaper" << 
			" or equal to your budget: ";
			std::cin >> budget;
			// Checks if budget is positive
			bool pos_check = positive_checker(budget);
			if (!pos_check) {
				std::cout << std::endl; // For formating
			}
		} while (budget < 0);
		std::cout << std::endl;

		// Prints coffee items that are equal or lower than budget
		s.get_menu().print_coffee_budget_search(budget);
		std::cout << std::endl;
	} else if (option == 6) {
		// Create menu from menu.txt and checks if it can be opened
		std::ifstream menu_file;
		menu_file.open("menu.txt");
		if (file_open_check(menu_file, option) == false) {
			return;
		}
		s.get_menu().print_menu(menu_file, option);
		std::cout << std::endl;

		// Ensures order option from user is valid
		int order_option = 0; 
		get_coffee_selection (order_option, option, 
			s.get_menu().get_num_coffees());
		std::cout << std::endl;
		
		// Gets name of coffee from users order option
		std::string coffee_name = s.get_menu().coffee_name(order_option - 1);
		// Prints coffee size prices
		s.get_menu().print_coffee(order_option - 1);

		// Gets coffee size from user and ensures its valid
		char size;
		get_coffee_size(size);
		std::cout << std::endl;
	
		int quantity = 0; // Quantity variable from user
		// Repeats until valid quantity is given
		do {
			std::cout << "Enter quanitiy: ";
			std::cin >> quantity;
			std::cout << std::endl;
			if (quantity == 0) {
				std::cout << "Enter a valid number/option!" << std::endl;
			}
		} while (!positive_checker(quantity) || quantity == 0);
		
		// Create order object with given order number, coffee name, 
		// size and quantity that were validated
		order user_order(((s.get_num_orders()) + 1), coffee_name, size, 
			quantity);
		// Determines cost from given quantity and pricing per size selected
		double cost = s.total_cost(quantity, size, order_option);
		int confirm = 0; // Confirm prompt variable
		// Repeats until valid confirmation input is given
		do {
			// Prints out cost and prompts if correct
			std::cout << "Your total cost is: " << cost << std::endl;
			std::cout << "Confirmed? 1-yes, 0-no: ";
			std::cin >> confirm;
			std::cout << std::endl;
			// Runs if user selects correct(1)
			if (confirm == 1) {
				// Sets revenue with added cost
				s.set_revenue(s.get_revenue() + cost);
				// Adds order to order array
				s.add_order(user_order);
				// Writes order to output file "orders.txt"
				std::ofstream output_file ("orders.txt");
				s.print_order_file(output_file);
				// Gives user their order number
				std::cout << "Your order has been placed! Your order number "
				<< s.get_num_orders() << std::endl;
				std::cout << std::endl;
			// Runs if user selects incorrect(0)
			} else if (confirm == 0) {
				std::cout << "Try again!" << std::endl;
				std::cout << std::endl;
				return;
			// Checks if confirm input is within boundaries, 0 or 1
			} else if (confirm > 1 || confirm < 0) {
				std::cout << "Enter a valid option!" << std::endl;
				std::cout << std::endl;
			}
		} while (confirm > 1 || confirm < 0);
	}
}
