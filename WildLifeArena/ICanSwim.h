#pragma once

// Interface for animals that can swim
class ICanSwim {
public:
    virtual void swim() const = 0; 
    virtual ~ICanSwim() = default;
};
