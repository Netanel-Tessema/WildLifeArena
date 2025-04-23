#pragma once

// Interface for animals that can fly
class ICanFly {
public:
    virtual void fly() const = 0; 
    virtual ~ICanFly() = default;
};
