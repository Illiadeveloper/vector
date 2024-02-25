#pragma once
#include <iostream>


template<class _Myvec>
class _Vector_const_iterator {
public:
	using value_type = typename _Myvec::value_type;
	using difference_type = typename _Myvec::difference_type;
	using pointer = typename _Myvec::const_pointer;
	using reference = typename _Myvec::const_reference;

	using _Tptr = typename _Myvec::pointer;

	inline _Vector_const_iterator();

	inline _Vector_const_iterator(_Tptr _ptr);

	inline reference operator*();

	inline pointer operator->();

	inline _Vector_const_iterator& operator++();

	inline _Vector_const_iterator& operator++(int);

	inline _Vector_const_iterator& operator--();

	inline _Vector_const_iterator& operator--(int);

	inline void _Verify_offset(const difference_type Off);

	inline _Vector_const_iterator& operator+=(const difference_type Off);

	inline _Vector_const_iterator operator+(const _Vector_const_iterator& _Right);

	inline _Vector_const_iterator& operator-=(const difference_type Off);

	inline _Vector_const_iterator operator-(const _Vector_const_iterator& _Right);

	inline reference operator[](const difference_type Off);

	inline bool operator==(const _Vector_const_iterator& _Right);

	inline bool operator!=(const _Vector_const_iterator& _Right);

	inline bool operator<(const _Vector_const_iterator& _Right);

	inline bool operator>(const _Vector_const_iterator& _Right);

	inline bool operator<=(const _Vector_const_iterator& _Right);

	inline bool operator>=(const _Vector_const_iterator& _Right);

private:
	_Tptr _Ptr;
};

template <class _Ty, class _Alloc>
class Vector {
private:
	using _Alty = _STD _Rebind_alloc_t<_Alloc, _Ty>;
	using _Alty_trains = _STD allocator_traits<_Alty>;

public:
	using value_type = _Ty;
	using allocator_type = _Alloc;
	using pointer = typename _Alty_trains::pointer;
	using const_pointer = typename _Alty_trains::const_pointer;
	using reference = _Ty&;
	using const_reference = const _Ty&;
	using size_type = typename _Alty_trains::size_type;
	using difference_type = typename _Alty_trains::difference_type;
};