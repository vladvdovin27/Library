#ifndef LIBRARY_MSE_H
#define LIBRARY_MSE_H

#include <vector>
#include <Math.h>

class MSE {
public:
    float static countError(std::vector<float> target, std::vector<float> prediction) {
        float error = 0;
        for (int i = 0; i < target.size(); i++) {
            cout << "TARGET: " << target[i] << " PRED: " << prediction[i] << endl;
            error += pow(target[i], 2) - pow(prediction[i], 2);
        }
        error /= target.size();

        return error;
    }

    std::vector<float> static getGradient(std::vector<float> prediction){
        std::vector<float> result;

        for(auto elm : prediction){
            result.push_back(-(2.0f * elm) / prediction.size());
        }

        for(auto elm: result){
            cout << elm << " ";
        }
        cout << endl;

        return result;
    }
};


#endif //LIBRARY_MSE_H
