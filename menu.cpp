#include "menu.h"

menu::menu() {} // Default constructor

// Setter for num_coffees
void menu::set_num_coffees(int new_num) {
	this->num_coffees = new_num; 
}

// Creates coffees array from menu.txt
void menu::make_coffee_menu(std::ifstream& file){
	// Sets num_coffees from menu.txt
	int new_num = 0;
	file >> new_num;
	set_num_coffees(new_num);
	// Deletes previous coffees array if present
	if (this->coffees != nullptr) {
		delete [] coffees;
	}
	// Coffees array set with coffee info
	this->coffees = new coffee[num_coffees];
	for (int i = 0; i < this->num_coffees; i++) {
		coffees[i].set_coffee_info(file);
	}
}

// Coffee info printed to terminal 
void menu::print_menu(std::ifstream& file, const int& option) {
	// Coffee array made
	make_coffee_menu(file);
	for (int i = 0; i < this->num_coffees; i++){
		std::cout << i+1 << ". ";
		// All information of coffees is printed
		if (option == 1 || option == 4) {
			coffees[i].print_coffee_info();
		} else {
			// Only names of coffees printed for other options
			std::cout << coffees[i].get_name();
			std::cout << std::endl;
		}	
	}
}

// Adds coffee to coffee array
void menu::add_coffee(const coffee& c){
	// Creates new array of coffees with additional spot
	coffee* new_coffee_array = new coffee[this->num_coffees + 1];
	// Copies over data from old array
	for (int i = 0; i < this->num_coffees; i++) {
		new_coffee_array[i] = this->coffees[i];
	}
	// Sets additional spot to given coffee object
	new_coffee_array[this->num_coffees] = c;
	// Deletes old array
	if (this->coffees != nullptr) {
		delete [] coffees;
	}
	// Sets pointer to new array and increments num_coffees
	this->coffees = new_coffee_array;
	this->num_coffees++;
}

// Getter for num_coffees
int menu::get_num_coffees() const{
	return this->num_coffees;
}

// Getter for name of coffee at given index
std::string menu::coffee_name (const int& index) const{
	return this->coffees[index].get_name();
}

// Updates menu.txt with current array 
void menu::print_array_file(std::ofstream& file) const{
	file << this->num_coffees << std::endl;
	for (int i = 0; i < this->num_coffees; i++) {
	file << this->coffees[i].get_name() << " " 
		<< this->coffees[i].get_sm_price() 
		<< " " << this->coffees[i].get_m_price() << " "  
		<< this->coffees[i].get_lg_price() << std::endl;
	}
}

// Deletes coffee from coffees array
void menu::delete_coffee(const int& index) {
	// Determines if index is a valid number
	if (index < 1 || index > num_coffees) {
		std::cout << "Invalid option!" << std::endl;
		return;
	}
	// Creates new coffee array with one less spot
	coffee* new_coffee_array = new coffee[this->num_coffees - 1];
	int new_index = 0; // Index variable for new array
	for (int i = 0; i < this->num_coffees; i++) {
		// Runs when i is not equal to coffee selected by user (index-1)
		if (i != index-1) {
				// Coffee info copied over and new index incremented
				new_coffee_array[new_index] = this->coffees[i];
				new_index++;
		}
	}
	// Deletes old array
	if (this->coffees != nullptr) {
		delete [] coffees;
	}
	// Sets pointer to new array and decreases num_coffees
	this->coffees = new_coffee_array;
	this->num_coffees--;

}

// Prints info of coffee search if avaliable
void menu::print_coffee_name_search(const std::string& user_name) const{
	// Checks if coffee exists with given name from user
	for (int i = 0; i < this->num_coffees; i++) {
		// Prints coffee info if there was a match
		if (user_name == this->coffees[i].get_name()) {
			std::cout << "Results:" << std::endl;
			std::cout << "1. ";
			coffees[i].print_coffee_info();
		// Prints message when there was not match
		} else if (user_name != this->coffees[i].get_name() 
			&& i == this->num_coffees - 1) {
			std::cout << "Sorry, we don't have that product at the moment."
				<< std::endl << std::endl;
			return;
		}
	}
}

// Prints all coffees and their sizes that are within the budget
void menu::print_coffee_budget_search(const double& budget) const{
	bool valid = false; // bool to check if items found within budget
	// Checks if items found within budget
	for (int i = 0; i < this->num_coffees; i++) {
		// Runs when budget meets small price of coffee at index i
		if (budget >= this->coffees[i].get_sm_price()) {
			valid = true;
			// Prints coffee information for small price
			std::cout << i+1 << ". ";
			std::cout << this->coffees[i].get_name() << std::endl;
			std::cout << "   Small - " << this->coffees[i].get_sm_price() 
				<< std::endl;
			// Runs when budget meets medium price of coffee
			if (budget >= this->coffees[i].get_m_price()) {
				std::cout << "   Medium - " << this->coffees[i].get_m_price() 
					<< std::endl;
			} 
			// Runs when budget meets large price of coffee
			if (budget >= this->coffees[i].get_lg_price()) {
				std::cout << "   Large - " << this->coffees[i].get_lg_price() 
					<< std::endl;
			} 
		} 
	}
	// Runs when no items were found within the budget
	if (valid == false) {
		std::cout << "No items found within your budget!" << std::endl;
		return;
	}
}

// Getters for prices of coffees at given index
double menu::sm_price (const int& index) const{
	return this->coffees[index].get_sm_price();
}
double menu::m_price (const int& index) const{
	return this->coffees[index].get_m_price();
}
double menu::lg_price (const int& index) const{
	return this->coffees[index].get_lg_price();
}

// Prints coffee info at given index
void menu::print_coffee (const int& index) const{
	this -> coffees[index].print_coffee_info();
}

// Destructor
menu::~menu(){ 
	delete [] coffees; 
}

// Copy constuctor
menu::menu(const menu& m) : num_coffees(m.num_coffees){
	this->num_coffees = m.num_coffees;
	// Peforms deep copy of coffees array when coffees exist within array
	if (num_coffees > 0) {
		this->coffees = new coffee[num_coffees];
		for (int i = 0; i < num_coffees; i++) {
			this->coffees[i] = m.coffees[i];
		}
	} else {
		this->coffees = nullptr;
	}
}

// Assignment operator overload
menu& menu::operator=(const menu& m) {
	// Checks if current menu is trying to be copied to itself
	if (this == &m) {
		return *this;
	}
	// Copies num_coffees
	this->num_coffees = m.num_coffees;

	// Deletes coffees array if present
	if (this->coffees != NULL) {
		delete [] this->coffees;
	}
	
	// Copies array
	if (num_coffees > 0) {
		this->coffees = new coffee[num_coffees];
		for (int i = 0; i < num_coffees; i++) {
			this->coffees[i] = m.coffees[i];
		}
	} else {
		this->coffees = nullptr;
	}
	return *this;
}
