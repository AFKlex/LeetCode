#include "helper.h"
#include <iostream>

// Definition of the function template outside the class definition
template<typename T>
void helper::printVector(std::vector<T> input) {
    for(const auto &element : input) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

template void helper::printVector(std::vector<int> input);
