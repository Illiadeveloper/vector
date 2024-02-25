#include <iostream>
#include <vector>
#include "ymemory.h"

class EmptyClass {};

class _Temp {
public:
    _Temp() : pair1(_VEC _Zero_then_variadic_args_t{}, 12) {}
    int Foo() {
        return sizeof(pair1);
    }
private:
    _VEC _Compressed_pair<EmptyClass, int> pair1;
};

int main() {
    _Temp t;
    std::cout << "_Compresse_pair: " << t.Foo() << std::endl;
    std::cout << "Usually: " << sizeof(EmptyClass) + sizeof(12) << std::endl;
    return 0;
}