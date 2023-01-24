//
// Created by vlads on 24.01.2023.
//

#ifndef LIBRARY_MSE_H
#define LIBRARY_MSE_H
#include <vector>
#include <Math.h>
#include "Function.h"


class MSE : Function{
public:
    float static countError(std::vector<float> target, std::vector<float> prediction){
        float error;
        for(int i = 0;i < target.size();i++) {
            error += pow(target[i], 2) - pow(prediction[i], 2);
        }
        error /= target.size();

        return error;
    }
};


#endif //LIBRARY_MSE_H
