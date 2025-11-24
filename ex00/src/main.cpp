#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include "doctest.h"


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

TEST_CASE("Animal sounds and types")
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const WrongAnimal* wrongCat = new WrongCat();

    CHECK(dog->getType() == "Dog");
    CHECK(cat->getType() == "Cat");
    CHECK(wrongCat->getType() == "WrongCat");

    std::ostringstream dogSound;
    std::ostringstream catSound;
    std::ostringstream wrongCatSound;

    {
        std::streambuf* oldCoutBuf = std::cout.rdbuf();
        std::cout.rdbuf(dogSound.rdbuf());
        dog->makeSound();
        std::cout.rdbuf(oldCoutBuf);
    }

    {
        std::streambuf* oldCoutBuf = std::cout.rdbuf();
        std::cout.rdbuf(catSound.rdbuf());
        cat->makeSound();
        std::cout.rdbuf(oldCoutBuf);
    }

    {
        std::streambuf* oldCoutBuf = std::cout.rdbuf();
        std::cout.rdbuf(wrongCatSound.rdbuf());
        wrongCat->makeSound();
        std::cout.rdbuf(oldCoutBuf);
    }

    CHECK(dogSound.str() == "Woof\n");
    CHECK(catSound.str() == "Meow\n");
    CHECK(wrongCatSound.str() == "WrongAnimal sound\n");

    delete wrongCat;
    delete dog;
    delete cat;
}