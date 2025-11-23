//
// Created by tomjo on 29/10/2025.
//

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public virtual AAnimal
{
	private:
		Brain* brain;
	public:
        Cat();
        virtual ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        virtual void makeSound() const;
};

#endif //CAT_HPP
