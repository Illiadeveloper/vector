#include <iostream>
#include <thread>
#include <vector>
#include "ymemory.h"
#include "Vector.h"

using namespace vec;

int main() {
    std::vector<int> vec = { 1,2,3,4,5 };

    _Vector_const_iterator<std::vector<int>> iter(vec.data(), nullptr);

    std::cout << "Dereferencing iterator: " << *iter << std::endl;

    ++iter;
    std::cout << "After incrementing, value: " << *iter << std::endl;

    --iter;
    std::cout << "After decrementing, value: " << *iter << std::endl;

    _Vector_const_iterator<std::vector<int>> iter2 = iter + 2;
    std::cout << "After advancing by 2, value: " << *iter2 << std::endl;

    return 0;
}