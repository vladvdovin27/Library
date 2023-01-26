#ifndef LIBRARY_MODEL_H
#define LIBRARY_MODEL_H

#include "Layers/LinearLayer.h"
#include "Layers/layerWrap.h"
#include "LossFunc/funcWrap.h"
#include "lib.h"
#include <utility>
#include <vector>

using namespace std;
using namespace lib;


class Model {
    std::vector<layerWrap> layers;
    functionWrap lossFunc = functionWrap("mse");
    float learningRate;
    int layersNumb = 0;

public:

    Model(float learningRate, functionWrap lossFunc){
        this->lossFunc = functionWrap(lossFunc.type);
        this->learningRate = learningRate;
    };

    vector<float> forward(vector<float> data) {
        vector<float> X = std::move(data);
        for (auto layer: this->layers) {
            X = layer.forward(X);
        }

        return X;
    }

    void fitModel(vector<float> target, const vector<float>& predict) {
        // Method for learn a model
        float loss = this->lossFunc.countError(std::move(target), predict);
        cout << "LOSS: " << loss << std::endl;
        vector<float> newErrors = this->lossFunc.getGradient(predict);
        for (int i = this->layersNumb - 1; i >= 0; i--) {
            newErrors = this->layers[i].backward(newErrors, this->learningRate);
        }
    }

    void add(LinearLayer newLayer) {
        // Add a new linear layer in model
        layerWrap wrap = layerWrap(newLayer);
        this->layers.push_back(wrap);
        this->layersNumb++;
    }

    void train(vector<vector<float>> data, vector<vector<float>> target, int epochs) {
        // Method for a manage fit process
        vector<float> predict;
        for (int _ = 0; _ < epochs; _++) {
            for (int i = 0; i < data.size(); i++) {
                predict = this->forward(data[i]);
                this->fitModel(target[i], predict);
            }
        }
    };
};


#endif //LIBRARY_MODEL_H
