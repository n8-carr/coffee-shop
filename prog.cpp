/*
 * Author: Nathan Carrillo
 * Description: Coffee shop catalog that allows user to 
 * access shop info and modify info
 */

#include <iostream>
#include <fstream>
#include "display.h"

int main() {
	std::cout << "Welcome to the Coffee++ Cafe!" << std::endl;
	shop s; // Create shop object s
	
	// Open shop_info.txt to get address and phone number
	std::ifstream file;
	file.open("shop_info.txt");

	// Checks to see if file failed to open
	if (file.fail()) {
		std::cout << "Shop info file failed to open!" << std::endl;
		return 1;
	}
	// Populates shop info (address and phone num)
	s.populate_from_file(file);
	
	// Get option from user until log out prompt (7) is given
	int option;
	do {
		option = get_option();
		std::cin.ignore(); //Ignores newspace for future getline prompts
		if (option >= 1 && option <= 6) {
			execute_option(s, option);
		} else {
			std::cout << "Goodbye!" << std::endl;
		}
	} while (option != 7);

	return 0;
}
