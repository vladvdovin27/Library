#ifndef LIBRARY_INPUT_H
#define LIBRARY_INPUT_H
#include <vector>
using namespace std;

class Input {
    vector<float> data;

public:
    Input(vector<float> vec){
        for(auto e:vec){
            data.push_back(e);
        }
    }

    vector<float> getData(){
        return this->data;
    }
};


#endif //LIBRARY_INPUT_H
