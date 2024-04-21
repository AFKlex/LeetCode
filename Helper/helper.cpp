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


// Definition of the function template outside the class definition
template<typename A>
void helper::printVectorOfVector(std::vector<std::vector<A>> input) {
    std::cout << "Main Vector has Size: "<< input.size() << std::endl; 
    for(const auto &element : input) {
        helper::printVector(element);
    }
    std::cout << std::endl;
}

template void helper::printVectorOfVector(std::vector<std::vector<int>> input);
