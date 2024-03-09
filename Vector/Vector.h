#pragma once
#include <iostream>
#include "ymemory.h"

_VEC_BEGIN

template<class _Myvec>
class _Vector_const_iterator : public _Iterator_base12 {
public:
	using value_type = typename _Myvec::value_type;
	using difference_type = typename _Myvec::difference_type;
	using pointer = typename _Myvec::const_pointer;
	using reference = typename _Myvec::const_reference;

	using _Tptr = typename _Myvec::pointer;

	inline _Vector_const_iterator() noexcept : _Ptr() {}

	inline _Vector_const_iterator(_Tptr _ptr, const _Container_base12* _Cont) noexcept : _Ptr(_ptr) {
		this->_Adopt(_Cont);
	}

	inline reference operator*() const noexcept {
		return *_Ptr;
	}

	inline pointer operator->() const noexcept {
		return _Ptr;
	}

	inline _Vector_const_iterator& operator++() noexcept {
		++_Ptr;
		return *this;
	}

	inline _Vector_const_iterator& operator++(int) noexcept {
		_Vector_const_iterator* temp = *this;
		++*this;
		return temp;
	}

	inline _Vector_const_iterator& operator--() noexcept {
		--_Ptr;
		return *this;
	}

	inline _Vector_const_iterator& operator--(int) noexcept {
		_Vector_const_iterator* temp = *this;
		--*this;
		return temp;
	}

	inline void _Verify_offset(const difference_type Off) noexcept {
		const auto _Mycont = static_cast<const _Myvec*>(this->_Cont);
		if (Off == 0) { throw _STD exception("Off can't be zero"); }
		if (Off < 0) {
			if (Off < _Mycont->_Myfirst - _Ptr) {
				throw _STD exception("cannot seek vector iterator before begin");
			}
		}
		if (Off > 0) {
			if (Off > _Mycont->_Mylast - _Ptr) {
				throw _STD exception("cannot seek vector iterator before begin");
			}
		}
	}

	inline _Vector_const_iterator& operator+=(const difference_type Off) noexcept {
		_Verify_offset(Off);
		_Ptr += Off;
		return *this;
	}

	_NODISCARD inline _Vector_const_iterator operator+(const difference_type Off) const noexcept {
		_Vector_const_iterator _Temp = *this;
		_Temp += Off;
		return _Temp;
	}

	_NODISCARD_FRIEND inline _Vector_const_iterator operator+(
		const difference_type Off, _Vector_const_iterator _Next) noexcept {
		_Next += Off;
		return _Next;
	}

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


_VEC_END