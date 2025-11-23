//
// Created by tomjo on 29/10/2025.
//

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    // std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::~AAnimal() {
    // std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    // std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    // std::cout << "AAnimal assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

std::string AAnimal::getType() const {
    return this->type;
}

void AAnimal::makeSound() const {
    std::cout << "AAnimal sound" << std::endl;
}