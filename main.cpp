#include "Layers/LinearLayer.h"
#include "LossFunc/funcWrap.h"
#include "Model.h"

using namespace std;

int main() {
    functionWrap mseloss = functionWrap("mse");
    Model model = Model(0.1, mseloss);

    LinearLayer layer_1 = LinearLayer(3, 2, "random", true);
    LinearLayer layer_2 = LinearLayer(2, 1, "random", true);

    model.add(layer_1);
    model.add(layer_2);

    vector<vector<float>> data = {
            {0, 1, 0},
            {0, 1, 1},
            {1, 0, 1},
            {0, 0, 0},
            {1, 1, 1}
    };

    vector<vector<float>> targets = {
            {1},
            {1},
            {0},
            {0},
            {1}
    };

    model.train(data, targets, 32);

    return 0;
}
