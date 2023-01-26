#ifndef LIBRARY_LINEARLAYER_H
#define LIBRARY_LINEARLAYER_H

#include "../Matrix.h"
#include "../lib.h"

using namespace lib;


class LinearLayer {
    Matrix weights = Matrix(1, 1, 1.0f);
    vector<float> bias;
    layerType type = Linear;

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
        for (int i = 0; i < this->weights.getSize().second; i++) {
            result.push_back(0);
        }

        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < X.size(); j++) {
                result[i] += X[j] * this->weights[j][i];
            }
            result[i] += this->bias[i];
        }
        cout << endl;

        return result;
    };

    vector<float> backward(vector<float> errors, float learningRate) {
        vector<float> newErrors;
        for (int i = 0; i < this->weights.getSize().first; i++) {
            newErrors.push_back(0);
        }
        for (int i = 0; i < this->weights.getSize().second; i++) {
            for(int j = 0; j < this->weights.getSize().first; j++){
                this->weights[j][i] -= errors[i] * learningRate;
            }
        }

        for(int i = 0; i < this->weights.getSize().first;i++){
            for(int j = 0; j < this->weights.getSize().second;j++){
                newErrors[i] += errors[j] * this->weights[i][j];
            }
        }

        return newErrors;
    };

    pair<int, int> getInfo() {
        return this->weights.getSize();
    }

    layerType getType() {
        return this->type;
    }

};


#endif //LIBRARY_LINEARLAYER_H
