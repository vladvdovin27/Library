//
// Created by vlads on 24.01.2023.
//

#ifndef LIBRARY_LIB_H
#define LIBRARY_LIB_H

#include <utility>

#include "Layers/LinearLayer.h"

namespace lib{
    enum layerType {Linear, Convoluted1d, Convoluted2d, Convoluted3d};
    enum lossType {mse, rmse, mae, logLoss, ceLoss};
}

#endif //LIBRARY_LIB_H
