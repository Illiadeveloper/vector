#include <iostream>
#include <thread>
#include <vector>
#include "ymemory.h"

int main() {
    _STD allocator<_VEC _Container_proxy> al1;
    _STD allocator<_VEC _Container_proxy> al2;
    _VEC _Container_base12 _Cont1; 
    _VEC _Container_base12 _Cont2;
    _Cont1._Alloc_Proxy(al1);
    _Cont2._Alloc_Proxy(al2);
    _VEC _Iterator_base12 _iter1; _iter1._Adopt(&_Cont1);
    _VEC _Iterator_base12 _iter2; _iter2._Adopt(&_Cont2);
    _VEC _Iterator_base12 _iter3; _iter3._Adopt(&_Cont1);

    std::cout << "_iter1=" << &_iter1 << std::endl;
    std::cout << "_iter1.Proxy=" << _iter1._MyProxy << std::endl;
    std::cout << "_iter2=" << &_iter2 << std::endl;
    std::cout << "_iter2.Proxy=" << _iter2._MyProxy << std::endl;
    std::cout << "_iter3=" << &_iter3 << std::endl;
    std::cout << "_iter3.Proxy=" << _iter3._MyProxy << std::endl;

    std::cout << "\n_Cont1.Proxy= " << _Cont1._MyProxy;
    std::cout << "\n_Cont2.Proxy= " << _Cont2._MyProxy << "\n\n";

    std::cout << "_iter1.nextIter" << _iter1._MyNextIter << std::endl;
    std::cout << "_iter2.nextIter" << _iter2._MyNextIter << std::endl;
    std::cout << "_iter3.nextIter" << _iter3._MyNextIter << std::endl;

    _Cont1._Swap_proxy_and_iter(_Cont2);

    std::cout << "_iter1=" << &_iter1 << std::endl;
    std::cout << "_iter1.Proxy=" << _iter1._MyProxy << std::endl;
    std::cout << "_iter2=" << &_iter2 << std::endl;
    std::cout << "_iter2.Proxy=" << _iter2._MyProxy << std::endl;
    std::cout << "_iter3=" << &_iter3 << std::endl;
    std::cout << "_iter3.Proxy=" << _iter3._MyProxy << std::endl;

    std::cout << "\n_Cont1.Proxy= " << _Cont1._MyProxy;
    std::cout << "\n_Cont2.Proxy= " << _Cont2._MyProxy << "\n\n";

    std::cout << "_iter1.nextIter" << _iter1._MyNextIter << std::endl;
    std::cout << "_iter2.nextIter" << _iter2._MyNextIter << std::endl;
    std::cout << "_iter3.nextIter" << _iter3._MyNextIter << std::endl;

    return 0;
}