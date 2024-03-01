
# _Iterator_base12

## **Code:** [Vector/ymemory.h](../Vector/ymemory.h#L135)
**_Iterator_base12 - base class for container iterators.**

### Fields:
    _MyProxy: Pointer to the _Container_proxy object, which holds information about the iterator's connection to the container.

    _MyNextIter: Pointer to the next iterator in the container. Used for organizing a linked list of iterators within the container.

### Methods:
    _Adopt(const _Container_base12* _Parent): Establishes a connection between the iterator and the container specified by _Parent.

    ~_Iterator_base12(): Destructor, which detaches the iterator from the linked list of iterators in the container.

    _Cont() const noexcept: Returns a pointer to the container to which the iterator belongs.

### Functionality:
    Connection Management: _Iterator_base12 allows establishing a connection between the iterator and the container, enabling the iterator to access the container's data.

    Linked List Organization: The _MyNextIter field is used for organizing a linked list of iterators within the container, ensuring efficient iterator management.

    Memory Leak Prevention: The _Iterator_base12 destructor correctly detaches the iterator from the linked list of iterators, preventing memory leaks and other issues.

    Thread Safety: Methods of the _Iterator_base12 class are protected with locking to ensure safety in multithreaded access to the container data and iterators.