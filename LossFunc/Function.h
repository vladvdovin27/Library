//
// Created by vlads on 23.01.2023.
//

#ifndef LIBRARY_FUNCTION_H
#define LIBRARY_FUNCTION_H

#include <vector>

class Function {
public:
    virtual float countError(std::vector<float> target, std::vector<float> prediction);
};


#endif //LIBRARY_FUNCTION_H
