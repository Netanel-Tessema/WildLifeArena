# WildLife Arena

A console-based animal battle simulator written in C++. 
This project demonstrates key object-oriented programming concepts like inheritance, polymorphism, and abstract interfaces.

## Features
- Select from different animals with unique stats
- Turn-based battle system
- Critical hit and dodge chance
- Special ability per animal
- Interfaces for swim/fly behaviors
- Interactive menu for actions

## Animals
Each animal has its own stats and special move:
- **Elephant** – High health, powerful stomp
- **Parrot** – Agile, fast, aerial dive attack
- **Seal** – Balanced, spinning water strike
- **Giraffe** – Long-range neck whip

## Structure
- `Animal.h/cpp` – Base class with health, attack, and combat logic
- `GameEngine.cpp` – Game loop and battle mechanics
- `Elephant/Parrot/Seal/Giraffe` – Derived classes with overrides
- `ICanFly.h`, `ICanSwim.h` – Interfaces for animal-specific behaviors
