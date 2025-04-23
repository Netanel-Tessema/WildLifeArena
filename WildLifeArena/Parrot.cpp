#include "Parrot.h"
#include <iostream>

using namespace std;

Parrot::Parrot(const string& name, int age)
    : Animal(name, age) {
    // Parrot: low health, fast and agile
    health = 70;
    attackPower = 10;
    critChance = 0.3;    // High chance to crit
    dodgeChance = 0.25;  // Very agile
}

void Parrot::makeSound() const {
    cout << name << " says: 'Polly wants a cracker!'" << endl;
}

void Parrot::move() const {
    cout << name << " flaps its wings and flies." << endl;

}

void Parrot::fly() const {
    cout << name << " soars through the sky." << endl;
}


std::string Parrot::getType() const {
    return "Parrot";
}

void Parrot::useSpecial(Animal* target) {
    // Special ability: quick aerial dive attack
    cout << name << " uses special ability: DIVE BOMB!" << endl;
    int damage = attackPower + 5;
    cout << name << " deals " << damage << " damage from above to " << target->getName() << "!" << endl;
    target->takeDamage(damage);
}
