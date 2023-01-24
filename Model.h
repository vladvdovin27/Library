#ifndef LIBRARY_MODEL_H
#define LIBRARY_MODEL_H

#include "Layers/LinearLayer.h"
#include "LossFunc/MSE.h"
#include <utility>
#include <vector>


class Model {
    std::vector<Layer> layers;
    Function lossFunc;
    float learningRate;
public:
    Model(float learningRate, Function lossFunc) {
        this->lossFunc = std::move(lossFunc);
        this->learningRate = learningRate;
    };

    void add(Layer newLayer) {
        // Add a new layer in model
        this->layers.push_back(newLayer);
    }

    vector<float> forward(vector<float> data) {
        vector<float> X = std::move(data);
        for (Layer layer: this->layers) {
            X = layer.forward(X);
        }
        return X;
    }

    void fitModel(vector<float> target, vector<float> predict) {
        float loss = this->lossFunc.countError(target, predict);
        vector<float> newErrors;
        newErrors.push_back(loss);
        for (int i = this->layers.size() - 1; i >= 0; i++) {
            newErrors = this->layers[i].backward(newErrors, this->learningRate);
        }
    }

    void train(vector<float> data, vector<float> target, int epochs) {
        vector<float> predict;
        for (int _ = 0; _ < epochs; _++) {
            predict = this->forward(data);
            this->fitModel(target, predict);
        }
    };
};


#endif //LIBRARY_MODEL_H
