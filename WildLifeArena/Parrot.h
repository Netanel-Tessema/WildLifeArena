#pragma once
#include "Animal.h"
#include "ICanFly.h"

class Parrot : public Animal, public ICanFly {
public:
    Parrot(const std::string& name, int age);

    void makeSound() const override;
    void move() const override;
    std::string getType() const override;
    void useSpecial(Animal* target) override;  
    void fly() const override;
};
