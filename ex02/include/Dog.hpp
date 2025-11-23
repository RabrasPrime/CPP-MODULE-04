//
// Created by tomjo on 29/10/2025.
//

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public virtual AAnimal
{
	private:
		Brain* brain;
	public:
        Dog();
        virtual ~Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        virtual void makeSound() const;
};



#endif //DOG_HPP
