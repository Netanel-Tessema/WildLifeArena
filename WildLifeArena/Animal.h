#pragma once
#include <string>

class Animal {
protected:
    std::string name;
    int age;

    // Combat stats
    int health;           
    int attackPower;      
    double critChance;    
    double dodgeChance;   

public:
    Animal(const std::string& name, int age);
    virtual ~Animal() = default;

    // Core behaviors (abstract)
    virtual void makeSound() const = 0;
    virtual void move() const = 0;
    virtual std::string getType() const = 0;

    // Combat mechanics
    virtual void attack(Animal* target);           
    virtual void useSpecial(Animal* target) = 0;   
    virtual void takeDamage(int amount);           

   
    bool isAlive() const;      
    int getHealth() const;     
    std::string getName() const;
    int getAge() const;
};
