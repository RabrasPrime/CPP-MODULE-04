//
// Created by tomjo on 23/11/2025.
//

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource{
    private:
        AMateria* inventory[4];
    public:
        MateriaSource();
        virtual ~MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(std::string const & type);

};



#endif //MATERIASOURCE_HPP
