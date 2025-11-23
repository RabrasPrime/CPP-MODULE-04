//
// Created by tomjo on 23/11/2025.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character: public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
    public:
        Character();
        Character(const std::string& name);
        virtual ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);

};



#endif //CHARACTER_HPP
