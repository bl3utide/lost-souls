#ifndef ACTION_H
#define ACTION_H

#include <iostream>

class ActionBase {
public:
    virtual void execute() const = 0;

    void nl() const noexcept {
        std::cout << std::endl;
    }
};

#endif // ACTION_H
