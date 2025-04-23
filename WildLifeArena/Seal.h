#pragma once
#include "Animal.h"
#include "ICanSwim.h"

class Seal : public Animal, public ICanSwim {
public:
    Seal(const std::string& name, int age);

    void makeSound() const override;
    void move() const override;
    std::string getType() const override;
    void useSpecial(Animal* target) override;  
    void swim() const override;
};
