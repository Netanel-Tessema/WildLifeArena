#include "Seal.h"
#include <iostream>

using namespace std;

Seal::Seal(const string& name, int age)
    : Animal(name, age) {
    // Seal: balanced stats, decent agility
    health = 90;
    attackPower = 13;
    critChance = 0.1;
    dodgeChance = 0.2;
}

void Seal::makeSound() const {
    cout << name << " says: 'Arh Arh!'" << endl;
}

void Seal::move() const {
    cout << name << " slides on its belly and swims." << endl;
}

void Seal::swim() const {
    cout << name << " swims swiftly through the water." << endl;
}


std::string Seal::getType() const {
    return "Seal";
}

void Seal::useSpecial(Animal* target) {
    // Special ability: spinning aquatic attack
    cout << name << " uses special ability: TORPEDO SPIN!" << endl;
    int damage = static_cast<int>(attackPower * 1.5);
    cout << name << " hits with a spinning dive for " << damage << " damage!" << endl;
    target->takeDamage(damage);
}
