//
// Created by tomjo on 29/10/2025.
//

#ifndef DOG_HPP
#define DOG_HPP



class Dog : public virtual Animal
{
	public:
        Dog();
        virtual ~Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        void makeSound() const override;
};



#endif //DOG_HPP
