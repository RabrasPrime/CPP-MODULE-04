//
// Created by tomjo on 29/10/2025.
//

#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    this->brain = new Brain();
    // std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
    delete this->brain;
    // std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->brain = new Brain(*(other.brain));
    // std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    // std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *(this->brain) = *(other.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->brain;
}