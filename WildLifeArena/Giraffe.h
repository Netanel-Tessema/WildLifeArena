#pragma once
#include "Animal.h"

class Giraffe : public Animal {
public:
    Giraffe(const std::string& name, int age);

    void makeSound() const override;
    void move() const override;
    std::string getType() const override;
    void useSpecial(Animal* target) override;  
};
