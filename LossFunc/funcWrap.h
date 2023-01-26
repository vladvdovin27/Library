#ifndef LIBRARY_FUNCWRAP_H
#define LIBRARY_FUNCWRAP_H

#include <utility>
#include <vector>
#include "MSE.h"
#include "../lib.h"

using namespace lib;


class functionWrap {
    bool isMSE = false;

public:
    string type;
    explicit functionWrap(string type){
        if (type == "mse") {this->isMSE = true;}
        this->type=type;
    }

    float countError(std::vector<float> target, std::vector<float> prediction){
        if(this->isMSE){
            return MSE::countError(std::move(target), std::move(prediction));
        }
    }

    vector<float> getGradient(std::vector<float> prediction){
        if(this->isMSE){
            return MSE::getGradient(prediction);
        }
    }
};



#endif //LIBRARY_FUNCWRAP_H
