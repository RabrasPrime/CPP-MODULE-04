#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "Dog type: " << dog->getType() << std::endl;
    dog->makeSound();

    std::cout << "Cat type: " << cat->getType() << std::endl;
    cat->makeSound();

    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound();

    delete wrongCat;
    delete dog;
    delete cat;

    return 0;
}
