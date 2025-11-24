//
// Created by tjooris on 11/20/25.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include "doctest.h"

#include <iostream>
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

TEST_CASE("MateriaSource and Character functionality")
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");

    std::ostringstream useIceOutput;
    std::ostringstream useCureOutput;

    {
        std::streambuf* oldCoutBuf = std::cout.rdbuf();
        std::cout.rdbuf(useIceOutput.rdbuf());
        me->use(0, *bob);
        std::cout.rdbuf(oldCoutBuf);
    }

    {
        std::streambuf* oldCoutBuf = std::cout.rdbuf();
        std::cout.rdbuf(useCureOutput.rdbuf());
        me->use(1, *bob);
        std::cout.rdbuf(oldCoutBuf);
    }

    CHECK(useIceOutput.str() == "* shoots an ice bolt at bob *\n");
    CHECK(useCureOutput.str() == "* heals bob's wounds *\n");
    CHECK(me->getName() == "me");
    CHECK(bob->getName() == "bob");

    delete bob;
    delete me;
    delete src;
}
