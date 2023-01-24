//
// Created by vlads on 24.01.2023.
//

#ifndef LIBRARY_LAYER_H
#define LIBRARY_LAYER_H

#include <vector>
#include <utility>


class Layer {
public:
    virtual std::vector<float> forward(std::vector<float> X);
    virtual std::vector<float> backward(std::vector<float> errors, float learningRate);
    virtual std::pair<int, int> getInfo();
};


#endif //LIBRARY_LAYER_H
