//
// Created by tomjo on 18/11/2025.
//

#include "Brain.hpp"

Brain::Brain() {
    // std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain() {
    // std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    // std::cout << "Brain copy constructor called" << std::endl;
    (void)other;
}

Brain& Brain::operator=(const Brain& other) {
    // std::cout << "Brain assignment operator called" << std::endl;
    (void)other;
    return *this;
}