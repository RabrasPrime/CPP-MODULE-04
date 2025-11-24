//
// Created by tomjo on 29/10/2025.
//

#include "Dog.hpp"

Dog::Dog() : AAnimal() {
    this->type = "Dog";
    this->brain = new Brain();
    // std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() {
    delete this->brain;
    // std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    this->brain = new Brain(*(other.brain));
    // std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    // std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        *(this->brain) = *(other.brain);
    }
    return *this;
}

Brain* Dog::getBrain() const {
    return this->brain;
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}
