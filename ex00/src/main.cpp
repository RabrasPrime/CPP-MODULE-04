#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Dog type: " << dog->getType() << std::endl;
    dog->makeSound();

    std::cout << "Cat type: " << cat->getType() << std::endl;
    cat->makeSound();

    delete dog;
    delete cat;

    return 0;
}
