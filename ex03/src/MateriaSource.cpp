//
// Created by tomjo on 23/11/2025.
//

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    // std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i])
            delete this->inventory[i];
    }
    // std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    // std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    // std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (this->inventory[i])
                delete this->inventory[i];
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = m;
            return;
        }
    }
    // If inventory is full, do nothing
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] && this->inventory[i]->getType() == type) {
            return this->inventory[i]->clone();
        }
    }
    return NULL;
}