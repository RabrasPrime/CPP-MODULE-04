//
// Created by tomjo on 23/11/2025.
//

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public virtual AMateria
{
    public:
        Cure();
        virtual ~Cure();
        Cure(const Cure& other);
        Cure& operator=(const Cure& other);
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};



#endif //CURE_HPP
