#ifndef LIBRARY_LAYERWRAP_H
#define LIBRARY_LAYERWRAP_H

#include <vector>
#include <utility>
#include "LinearLayer.h"


class layerWrap{
    LinearLayer linLayer = LinearLayer(1, 1, "random", true);

    bool isLin = false;

public:
     explicit layerWrap(LinearLayer layer) {
        this->linLayer = std::move(layer);
        this->isLin = true;
    }

    vector<float> forward(vector<float> X){
         if(this->isLin){
             return this->linLayer.forward(X);
         }
     }

     vector<float> backward(vector<float> errors, float learningRate){
         if(this->isLin){
             return this->linLayer.backward(errors, learningRate);
         }
     }
};


#endif //LIBRARY_LAYERWRAP_H
