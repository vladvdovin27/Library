cmake_minimum_required(VERSION 3.23)
project(Library)

set(CMAKE_CXX_STANDARD 20)

add_executable(Library main.cpp Matrix.h Layers/LinearLayer.h Layers/Input.h LossFunc/funcWrap.h Model.h Layers/layerWrap.h LossFunc/MSE.h lib.h)
