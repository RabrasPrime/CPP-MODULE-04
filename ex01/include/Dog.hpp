//
// Created by tomjo on 29/10/2025.
//

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public virtual Animal
{
private:
	Brain* brain;
public:
	Dog();
	Brain* getBrain() const;
	virtual ~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	virtual void makeSound() const;
};

#endif //DOG_HPP
