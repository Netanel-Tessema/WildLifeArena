#include "Animal.h"
#include "Giraffe.h"
#include "Elephant.h"
#include "Parrot.h"
#include "Seal.h"
#include "ICanFly.h"
#include "ICanSwim.h"
#include <iostream>
#include <vector>

using namespace std;

// Battle logic with turns, dodge, crit, and special abilities
void startBattle(Animal* a1, Animal* a2) {
    cout << "\n=== Battle Start! ===\n";
    cout << a1->getName() << " (" << a1->getType() << ") vs "
        << a2->getName() << " (" << a2->getType() << ")\n";

    int round = 1;
    while (a1->isAlive() && a2->isAlive()) {
        cout << "\n-- Round " << round++ << " --\n";

        // Player 1 attacks
        a1->attack(a2);
        if (!a2->isAlive()) break;

        // Player 2 attacks
        a2->attack(a1);
        if (!a1->isAlive()) break;

        cout << a1->getName() << " HP: " << a1->getHealth() << endl;
        cout << a2->getName() << " HP: " << a2->getHealth() << endl;

        // Offer special ability after round 2
        if (round > 2 && round % 2 == 1) {
            cout << "\nWould you like " << a1->getName() << " to use its SPECIAL? (1 = yes / 0 = no): ";
            int choice;
            cin >> choice;
            if (choice == 1 && a1->isAlive() && a2->isAlive())
                a1->useSpecial(a2);

            if (!a2->isAlive()) break;

            cout << "\nWould you like " << a2->getName() << " to use its SPECIAL? (1 = yes / 0 = no): ";
            cin >> choice;
            if (choice == 1 && a2->isAlive() && a1->isAlive())
                a2->useSpecial(a1);
        }
    }

    // Winner announcement
    if (a1->isAlive())
        cout << "\n\U0001F3C6 " << a1->getName() << " wins the battle!\n";
    else
        cout << "\n\U0001F3C6 " << a2->getName() << " wins the battle!\n";
}

void startGame() {
    vector<Animal*> animals;
    animals.push_back(new Giraffe("Luna", 5));
    animals.push_back(new Elephant("Dumbo", 10));
    animals.push_back(new Parrot("Polly", 2));
    animals.push_back(new Seal("Bubbles", 4));

    while (true) {
        cout << "\n=== WildLife Arena ===\n";
        cout << "Choose an animal:\n";
        for (size_t i = 0; i < animals.size(); ++i)
            cout << i + 1 << ". " << animals[i]->getName() << " (" << animals[i]->getType() << ")\n";

        cout << animals.size() + 1 << ". Battle Mode\n";
        cout << animals.size() + 2 << ". Exit\n>> ";

        int choice;
        cin >> choice;

        if (choice == animals.size() + 2) break;

        if (choice == animals.size() + 1) {
            cout << "Choose first animal:\n";
            for (size_t i = 0; i < animals.size(); ++i)
                cout << i + 1 << ". " << animals[i]->getName() << endl;
            int i1, i2;
            cin >> i1;

            cout << "Choose second animal:\n";
            for (size_t i = 0; i < animals.size(); ++i)
                if (i + 1 != i1)
                    cout << i + 1 << ". " << animals[i]->getName() << endl;
            cin >> i2;

            if (i1 >= 1 && i2 >= 1 && i1 <= animals.size() && i2 <= animals.size() && i1 != i2)
                startBattle(animals[i1 - 1], animals[i2 - 1]);
            else
                cout << "Invalid selection.\n";
            continue;
        }

        if (choice < 1 || choice > animals.size()) {
            cout << "Invalid choice.\n";
            continue;
        }

        Animal* selected = animals[choice - 1];
        cout << "\nYou selected " << selected->getName() << " the " << selected->getType() << "!\n";
        cout << "Available actions:\n1. Make Sound\n2. Move\n";

        ICanFly* flyer = dynamic_cast<ICanFly*>(selected);
        if (flyer) cout << "3. Fly\n";

        ICanSwim* swimmer = dynamic_cast<ICanSwim*>(selected);
        if (swimmer) cout << "4. Swim\n";

        cout << ">> ";
        int action;
        cin >> action;

        switch (action) {
        case 1:
            selected->makeSound(); break;
        case 2:
            selected->move(); break;
        case 3:
            if (flyer) flyer->fly(); else cout << "This animal can't fly!\n"; break;
        case 4:
            if (swimmer) swimmer->swim(); else cout << "This animal can't swim!\n"; break;
        default:
            cout << "Invalid action.\n";
        }
    }

    for (Animal* a : animals)
        delete a;

    cout << "\nThanks for playing!\n";
}
