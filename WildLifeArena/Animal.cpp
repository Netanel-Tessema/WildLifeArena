#include "Animal.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Animal::Animal(const string& name, int age)
    : name(name), age(age), health(100), attackPower(10), critChance(0.1), dodgeChance(0.1) {
    srand((unsigned int)time(nullptr));  // Initialize random seed
}

void Animal::attack(Animal* target) {
    // Check if the target dodges the attack
    if ((rand() % 100) < (int)(target->dodgeChance * 100)) {
        cout << target->getName() << " dodged the attack!" << endl;
        return;
    }

    int damage = attackPower;

    // Check if this attack is critical
    if ((rand() % 100) < (int)(critChance * 100)) {
        damage *= 2;
        cout << name << " lands a CRITICAL HIT!" << endl;
    }

    // Apply damage to target
    cout << name << " attacks " << target->getName() << " for " << damage << " damage!" << endl;
    target->takeDamage(damage);
}

void Animal::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

bool Animal::isAlive() const {
    return health > 0;
}

int Animal::getHealth() const {
    return health;
}

std::string Animal::getName() const {
    return name;
}

int Animal::getAge() const {
    return age;
}
