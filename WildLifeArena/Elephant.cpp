#include "Elephant.h"
#include <iostream>

using namespace std;

Elephant::Elephant(const string& name, int age)
    : Animal(name, age) {
    // Elephant stats: tanky but not agile
    health = 130;
    attackPower = 20;
    critChance = 0.15;
    dodgeChance = 0.05;
}

void Elephant::makeSound() const {
    cout << name << " says: Pawoo!" << endl;
}

void Elephant::move() const {
    cout << name << " stomps across the ground." << endl;
}

std::string Elephant::getType() const {
    return "Elephant";
}

void Elephant::useSpecial(Animal* target) {
    // Special ability: strong stomp with double damage
    cout << name << " uses special ability: EARTH-SHAKING STOMP!" << endl;
    int damage = attackPower * 2;
    cout << name << " deals " << damage << " damage to " << target->getName() << "!" << endl;
    target->takeDamage(damage);
}
