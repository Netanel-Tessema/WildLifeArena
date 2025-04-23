#pragma once
#include "Animal.h"

class Elephant : public Animal {
public:
    Elephant(const std::string& name, int age);

    void makeSound() const override;
    void move() const override;
    std::string getType() const override;
    void useSpecial(Animal* target) override; 
};
