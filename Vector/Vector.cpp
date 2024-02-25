#include <iostream>
#include <vector>
#include "ymemory.h"

class EmptyClass {};

class _TempFields {
public:
    _TempFields() : num(12) {}
    _STD allocator<int> alloc;
    int num;
};

class _TempCompressedPair {
public:
    _TempCompressedPair() : pair1(_VEC _Zero_then_variadic_args_t{}, 12) {}
private:
    _VEC _Compressed_pair<_STD allocator<int>, int> pair1;
};

int main() {
    _TempFields fields;
    _TempCompressedPair compressedPair;

    std::cout << "Size of _TempFields: " << sizeof(fields) << std::endl;
    std::cout << "Size of _TempCompressedPair: " << sizeof(compressedPair) << std::endl;

    return 0;
}