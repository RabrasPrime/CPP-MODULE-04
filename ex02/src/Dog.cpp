//
// Created by tomjo on 29/10/2025.
//

#include "Dog.hpp"

Dog::Dog() : AAnimal() {
    this->type = "Dog";
    // std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() {
    // std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    // std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    // std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}
