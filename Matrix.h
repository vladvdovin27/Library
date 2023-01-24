#ifndef LIBRARY_MATRIX_H
#define LIBRARY_MATRIX_H

#include <iostream>
#include<vector>
#include <cstdlib>
#include<utility>

using namespace std;

class Matrix {
    vector<vector<float>> values;
    pair<int, int> size;

public:
    Matrix(int rows, int cols, bool random) {
        if (!random) this->initZeros(rows, cols);
        else this->initRandom(rows, cols);
        this->size = {rows, cols};
    }

    Matrix(int rows, int cols, float element) {
        vector<float> help_vec;
        for (int i = 0; i < rows; i++) {
            help_vec.clear();
            for (int j = 0; j < cols; j++) {
                help_vec.push_back(element);
            }
            this->values.push_back(help_vec);
        }
        this->size = {rows, cols};
    }

    Matrix(){
        this->size = {0, 0};
    }

    void initZeros(int rows, int cols) {
        vector<float> help_vec;
        for (int i = 0; i < rows; i++) {
            help_vec.clear();
            for (int j = 0; j < cols; j++) {
                help_vec.push_back(0);
            }
            this->values.push_back(help_vec);
        }
    }

    void initRandom(int rows, int cols) {
        vector<float> help_vec;
        for (int i = 0; i < rows; i++) {
            help_vec.clear();
            for (int j = 0; j < cols; j++) {
                help_vec.push_back((float) rand() / 32708.0f);
            }
            this->values.push_back(help_vec);
        }
    }

    void printMatrix() {
        for (int i = 0; i < this->size.first; i++) {
            for (int j = 0; j < this->size.second; j++) {
                cout << this->values[i][j] << " ";
            }
            cout << endl;
        }
    }

    pair<int, int> getSize() {
        return this->size;
    }

    void setElement(int i, int j, float elm) {
        this->values[i][j] = elm;
    }

    vector<float> operator[](int d) {
        return this->values[d];
    }

    Matrix operator+(Matrix mat) {
        pair<int, int> size_2 = mat.getSize();
        Matrix newMat = Matrix(this->size.first, this->size.second, false);

        if (this->size.first == size_2.first && this->size.second == size_2.second) {
            for (int i = 0; i < this->size.first; i++) {
                for (int j = 0; j < this->size.second; j++) {
                    newMat.setElement(i, j, this->values[i][j] + mat[i][j]);
                }
            }
        }
        return newMat;
    }

    Matrix operator*(float n) {
        Matrix newMat = Matrix(this->size.first, this->size.second, false);

        for (int i = 0; i < this->size.first; i++) {
            for (int j = 0; j < this->size.second; j++) {
                newMat.setElement(i, j, this->values[i][j] * n);
            }
        }

        return newMat;
    }

    Matrix operator*(Matrix mat) {
        pair<int, int> size_2 = mat.getSize();
        vector<float> helpVec;
        int currentRow = 0, currentCol;
        float newElement;
        Matrix newMat = Matrix(this->size.first, size_2.second, false);

        if (this->size.second == size_2.first) {
            helpVec.clear();
            while (currentRow < this->size.first) {
                currentCol = 0;
                while (currentCol < size_2.second) {
                    newElement = 0;
                    for (int i = 0; i < this->size.first; i++) {
                        newElement += this->values[currentRow][i] * mat[i][currentCol];
                    }
                    newMat.setElement(currentRow, currentCol, newElement);
                    currentCol++;
                }
                currentRow++;
            }
        }

        return newMat;
    }

    void push(vector<float> newVector){
        this->values.push_back(newVector);
        this->size.first++;
        if(this->size.second == 0) this->size.second = newVector.size();
    }
};


#endif //LIBRARY_MATRIX_H
