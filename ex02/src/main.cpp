#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include "doctest.h"


#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

TEST_CASE("AAnimal sounds and types")
{
    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

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

TEST_CASE("Array of AAnimals")
{
    const AAnimal* animals[4];
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

TEST_CASE("Brain deep copy")
{
    Dog originalDog;
    originalDog.getBrain()->ideas[0] = "Chase the cat";

    Dog copiedDog = originalDog;

    CHECK(copiedDog.getBrain()->ideas[0] == "Chase the cat");

    originalDog.getBrain()->ideas[0] = "Eat the bone";

    CHECK(copiedDog.getBrain()->ideas[0] == "Chase the cat");
    CHECK(originalDog.getBrain()->ideas[0] == "Eat the bone");
    CHECK(&originalDog.getBrain()->ideas[0] != &copiedDog.getBrain()->ideas[0]);
}
