//
// Created by tomjo on 18/11/2025.
//

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP



class WrongAnimal {
	protected:
        std::string type;
	public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
        void makeSound() const = 0;
        std::string getType() const;
};



#endif //WRONGANIMAL_HPP
