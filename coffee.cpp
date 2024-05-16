#include "coffee.h"

coffee::coffee() {}

coffee::coffee(const std::string& name, double sm_price, double m_price, 
		double lg_price) : name(name), small_cost(sm_price), 
		medium_cost(m_price), large_cost(lg_price){}
    
void coffee::set_coffee_info(std::ifstream& file){
    file >> this->name;
    file >> this->small_cost;
    file >> this->medium_cost;
    file >> this->large_cost;
}
   
void coffee::print_coffee_info() const{
    std::cout << this->name << std::endl;
    std::cout << "   Small - " << this->small_cost << std::endl;
    std::cout << "   Medium - " << this->medium_cost << std::endl;
    std::cout << "   Large - " << this->large_cost << std::endl;
    std::cout << std::endl;
}

std::string coffee::get_name() const{
    return this->name;
}

double coffee::get_sm_price() const{
    return this->small_cost;
}

double coffee::get_m_price() const{
    return this->medium_cost;
}

double coffee::get_lg_price() const{
    return this->large_cost;
}

