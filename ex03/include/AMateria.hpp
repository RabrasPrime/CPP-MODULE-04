//
// Created by tjooris on 11/20/25.
//

#ifndef CPP_MODULE_04_AMATERIA_H
#define CPP_MODULE_04_AMATERIA_H


#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
    protected:
        std::string type;
    public:
        AMateria();
        virtual ~AMateria();
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        AMateria(std::string const &type);

        std::string const &getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif //CPP_MODULE_04_AMATERIA_H