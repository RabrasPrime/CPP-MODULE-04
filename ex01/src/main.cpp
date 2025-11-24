#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include "doctest.h"

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

TEST_CASE("Animal sounds and types")
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    CHECK(dog->getType() == "Dog");
    CHECK(cat->getType() == "Cat");

    std::ostringstream dogSound;
    std::ostringstream catSound;

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

    CHECK(dogSound.str() == "Woof\n");
    CHECK(catSound.str() == "Meow\n");

    delete dog;
    delete cat;
}

TEST_CASE("Array of Animals")
{
    const Animal* animals[4];
    for (int i = 0; i < 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = 2; i < 4; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < 4; ++i) {
        if (i < 2) {
            CHECK(animals[i]->getType() == "Dog");
        } else {
            CHECK(animals[i]->getType() == "Cat");
        }
    }

    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }
}

TEST_CASE("Deep copy tests")
{
    Dog	d;

    d.getBrain()->ideas[5] = "idee";
    Dog	d2(d);
    CHECK(d.getBrain()->ideas[5] == d2.getBrain()->ideas[5]);
    CHECK(d.getBrain() != d2.getBrain());
    d2.getBrain()->ideas[5] = "change";
    CHECK(d.getBrain()->ideas[5] != d2.getBrain()->ideas[5]);
    Dog d3;
    d3 = d2;
    CHECK(d3.getBrain()->ideas[5] == d2.getBrain()->ideas[5]);
    CHECK(d3.getBrain() != d2.getBrain());
    d3.getBrain()->ideas[5] = "change_again";
    CHECK(d3.getBrain()->ideas[5] != d2.getBrain()->ideas[5]);
}
