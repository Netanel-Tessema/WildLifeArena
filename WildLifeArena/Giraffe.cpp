#include "Giraffe.h"
#include <iostream>

using namespace std;

Giraffe::Giraffe(const string& name, int age)
    : Animal(name, age) {
    // Giraffe: balanced health, moderate damage
    health = 100;
    attackPower = 15;
    critChance = 0.2;
    dodgeChance = 0.1;
}

void Giraffe::makeSound() const {
    cout << name << " makes a humming sound." << endl;
}

void Giraffe::move() const {
    cout << name << " walks gracefully with long steps." << endl;
}

std::string Giraffe::getType() const {
    return "Giraffe";
}

void Giraffe::useSpecial(Animal* target) {
    // Special ability: neck whip that adds bonus damage
    cout << name << " uses special ability: NECK WHIP!" << endl;
    int damage = attackPower + 8;
    cout << name << " strikes with neck for " << damage << " damage to " << target->getName() << "!" << endl;
    target->takeDamage(damage);
}
