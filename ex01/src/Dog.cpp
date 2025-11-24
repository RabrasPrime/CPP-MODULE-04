//
// Created by tomjo on 29/10/2025.
//

#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    this->brain = new Brain();
    // std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() {
    delete this->brain;
    // std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->brain = new Brain(*(other.brain));
    // std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    // std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *(this->brain) = *(other.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}

Brain* Dog::getBrain() const {
    return this->brain;
}