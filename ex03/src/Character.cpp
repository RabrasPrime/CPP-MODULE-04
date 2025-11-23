//
// Created by tomjo on 23/11/2025.
//

#include "Character.hpp"
#include <iostream>

Character::Character() : name("Default") {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    // std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string& name) : name(name) {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    // std::cout << "Character parameterized constructor called" << std::endl;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i])
            delete inventory[i];
    }
    // std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    // std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
    // std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; i++) {
            if (inventory[i])
                delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            // std::cout << "Equipped " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    // std::cout << "Inventory full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) {
        // std::cout << "Invalid index to unequip: " << idx << std::endl;
        return;
    }
    if (inventory[idx]) {
        // std::cout << "Unequipped " << inventory[idx]->getType() << " from slot " << idx << std::endl;
        inventory[idx] = NULL;
    } else {
        // std::cout << "No materia to unequip in slot " << idx << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) {
        // std::cout << "Invalid index to use: " << idx << std::endl;
        return;
    }
    if (inventory[idx]) {
        inventory[idx]->use(target);
    } else {
        // std::cout << "No materia to use in slot " << idx << std::endl;
    }
}
