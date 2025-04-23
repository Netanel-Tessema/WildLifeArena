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
    virtual void attack(Animal* target);           // Regular attack
    virtual void useSpecial(Animal* target) = 0;   // Special ability per animal
    virtual void takeDamage(int amount);           // Decrease health by damage

    // Info / utilities
    bool isAlive() const;      // Check if animal is still alive
    int getHealth() const;     // Get current HP
    std::string getName() const;
    int getAge() const;
};
