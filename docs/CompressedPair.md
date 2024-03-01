# _Compressed_Pair

## **Code:** [Vector/ymemory.h](../Vector/ymemory.h#L18)

    The _Compressed_pair class is a specialized container designed to reduce memory overhead by compressing two values into a single object. It optimizes memory usage when the first value is empty, achieving efficiency without sacrificing functionality.
## Example:
```C++
#include <iostream>
#include "ymemory.h"

int main() {
    // Define a class with two fields: an integer and an allocator
    class _TempFields {
    public:
        _TempFields() : num(12) {}
        _STD allocator<int> alloc;
        int num;
    };

    // Define a class using _Compressed_pair to compress an allocator and an integer
    class _TempCompressedPair {
    public:
        _TempCompressedPair() : pair1(_VEC _Zero_then_variadic_args_t{}, 12) {}
    private:
        _VEC _Compressed_pair<_STD allocator<int>, int> pair1;
    };

    // Create instances of the defined classes
    _TempFields fields;
    _TempCompressedPair compressedPair;

    // Output the sizes of the instances to compare memory usage
    std::cout << "Size of _TempFields: " << sizeof(fields) << std::endl;
    std::cout << "Size of _TempCompressedPair: " << sizeof(compressedPair) << std::endl;

    return 0;
}
```
## Result:
```
Size of _TempFields: 8
Size of _TempCompressedPair: 4
```
___
In this example, we define two classes: _TempFields with an integer field and an allocator, and _TempCompressedPair which uses _Compressed_pair to compress an allocator and an integer. We create instances of these classes and compare their sizes