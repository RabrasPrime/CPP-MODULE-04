//
// Created by tomjo on 29/10/2025.
//

#include "Cat.hpp"

Cat::Cat() : AAnimal() {
    this->type = "Cat";
    this->brain = new Brain();
    // std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
    delete this->brain;
    // std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    this->brain = new Brain(*(other.brain));
    // std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    // std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        *(this->brain) = *(other.brain);
    }
    return *this;
}

Brain* Cat::getBrain() const {
    return this->brain;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}
