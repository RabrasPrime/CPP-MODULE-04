//
// Created by tomjo on 29/10/2025.
//

#ifndef CAT_HPP
#define CAT_HPP



class Cat : public virtual Animal
{
	public:
        Cat();
        virtual ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        void makeSound() const override;
};



#endif //CAT_HPP
