#ifndef HELPER_H
#define HELPER_H

#include <vector>

class helper {
public:
    template<typename T>
    static void printVector(std::vector<T> input);

public:
    template<typename A>
    static void printVectorOfVector(std::vector<std::vector<A>> input);

};

#endif // End of header guard
