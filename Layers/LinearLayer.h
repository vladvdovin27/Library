//
// Created by vlads on 23.01.2023.
//

#ifndef LIBRARY_LINEARLAYER_H
#define LIBRARY_LINEARLAYER_H

#include "../Matrix.h"
#include "Layer.h"

class LinearLayer : Layer {
    Matrix weights = Matrix(1, 1, 1.0f);
    vector<float> bias;

public:
    LinearLayer(int input, int output, string initType, bool bias) {
        if (initType == "random") {
            weights = Matrix(input, output, true);
        } else {
            weights = Matrix(input, output, false);
        }
        if (bias) {
            for (int i = 0; i < weights.getSize().second; i++) {
                this->bias.push_back(rand() / 32708.0f);
            }
        } else {
            for (int i = 0; i < weights.getSize().second; i++) {
                this->bias.push_back(0);
            }
        }
    }

    vector<float> forward(vector<float> X) {
        vector<float> result;
        float currentResult;
        for (int i = 0; i < X.size(); i++) {
            currentResult = 0;
            for (int j = 0; j < weights.getSize().first; j++) {
                currentResult += X[i] * this->weights[j][i];
            }
            result.push_back(currentResult + this->bias[i]);
        }
        return result;
    };

    vector<float> backward(vector<float> errors, float learningRate) {
        vector<float> newErrors;
        float currentSum;
        for (int i = 0; i < this->weights.getSize().second; i++) {
            currentSum = 0;
            for (int j = 0; j < this->weights.getSize().first; j++) {
                this->weights[j][i] -= errors[i] * learningRate;
                currentSum += this->weights[j][i] * errors[i];
            }
            newErrors.push_back(currentSum);
        }

        return newErrors;
    };

    pair<int, int> getInfo(){
        return this->weights.getSize();
    }
};


#endif //LIBRARY_LINEARLAYER_H
