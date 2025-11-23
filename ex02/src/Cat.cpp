//
// Created by tomjo on 29/10/2025.
//

#include "Cat.hpp"

Cat::Cat() : AAnimal() {
    this->type = "Cat";
    // std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
    // std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    // std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    // std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}
