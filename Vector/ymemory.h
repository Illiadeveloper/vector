#pragma once
#include <iostream>

#define _VEC vec::
#define _VEC_BEGIN namespace vec {
#define _VEC_END }

_VEC_BEGIN
struct _Zero_then_variadic_args_t {
	explicit _Zero_then_variadic_args_t() = default;
};

struct _One_then_variadic_args_t {
	explicit _One_then_variadic_args_t() = default;
};

template<class _Ty1, class _Ty2, bool = _STD is_empty_v<_Ty1> && !_STD is_final_v<_Ty1>>
class _Compressed_pair final : private _Ty1 {
public:
	_Ty2 _Myval2;

	template<class... Other2>
	explicit _Compressed_pair(_Zero_then_variadic_args_t, Other2&&... args)
		: _Ty1(), _Myval2(_STD forward<Other2>(args)...) {}

	template<class Other1, class... Other2>
	explicit _Compressed_pair(_One_then_variadic_args_t, Other1&& args1, Other2... args2)
		: _Ty1(_STD forward<Other1>(args1)), _Myval2(_STD forward<Other2>(args2)...) {}

	_Ty1& _Get_First() noexcept {
		return *this;
	};

	const _Ty1& _Get_First() const noexcept {
		return *this;
	};
};

template<class _Ty1, class _Ty2>
class _Compressed_pair<_Ty1, _Ty2, false> final {
public:
	_Ty1 _Myval1;
	_Ty2 _Myval2;

	template<class... Other2>
	explicit _Compressed_pair(_Zero_then_variadic_args_t, Other2&&... args)
		: _Myval1(), _Myval2(_STD forward<Other2>(args)...) {}

	template<class Other1, class... Other2>
	explicit _Compressed_pair(_One_then_variadic_args_t, Other1&& args1, Other2... args2)
		: _Myval1(_STD forward<Other1>(args1)), _Myval2(_STD forward<Other2>(args2)...) {}

	_Ty1& _Get_First() noexcept {
		return *_Myval1;
	};

	const _Ty1& _Get_First() const noexcept {
		return *_Myval1;
	};
};

template<class _Ptrty>
_NODISCARD constexpr auto _Unfancy(_Ptrty _ptr) {
	return _STD addressof(*_ptr);
}
template<class _Ptr>
_NODISCARD constexpr _Ptr* _Unfancy(_Ptr* _ptr) {
	return _ptr;
}


class _Container_base12;
class _Iterator_base12;
struct _Container_proxy {

	inline _Container_proxy() noexcept = default;
	inline _Container_proxy(_Container_base12* _Cont) noexcept 
		: _MyCont(_Cont) {}

	const _Container_base12* _MyCont = nullptr;
	mutable _Iterator_base12* _MyfirstIter	= nullptr;
};


class _Container_base12 {
public:
	inline _Container_base12() noexcept = default;

	_Container_base12(const _Container_base12&) = delete;
	_Container_base12& operator=(const _Container_base12&) = delete;

	// destroed all conection with iterator 
	inline void _Orphan_all() {
		_Orphan_all_locked();
	}
	// Swap proxy
	inline void _Swap_proxy_and_iter(_Container_base12& _Cont) {
		if (_Cont._MyProxy == this->_MyProxy) return;
		_Swap_proxy_and_iter_locked(_Cont);
	}

	// Create _Container_Proxy12 
	template<class _Alloc>
	inline void _Alloc_Proxy(_Alloc&& _Al) {
		_Container_proxy* _New_Proxy = _Unfancy(_Al.allocate(1));
		_STD _Construct_in_place(*_New_Proxy, this);
		_MyProxy			= _New_Proxy;
		_New_Proxy->_MyCont = this;
	}
	// Reload _Container_Proxy12 
	template<class Alloc>
	inline void _Reload_Proxy(Alloc&& Old_Al, Alloc&& _New_Al) {
		_Container_proxy* _New_Proxy = _Unfancy(_New_Al.allocate(1));
		_STD _Construct_in_place(*_New_Proxy, this);
		_New_Proxy->_MyCont = this;
		_STD _Delete_plain_internal(Old_Al, _STD exchange(_MyProxy, _New_Proxy));
	}

	_Container_proxy* _MyProxy = nullptr;
private:
	inline void _Swap_proxy_and_iter_unlocked(_Container_base12&) noexcept;
	inline void _Orphan_all_unlocked() noexcept;

	inline void _Orphan_all_locked() noexcept {
		_STD _Lockit lock(_LOCK_DEBUG);
		_Orphan_all_unlocked();
	}

	inline void _Swap_proxy_and_iter_locked(_Container_base12& _Cont) noexcept {
		_STD _Lockit lock(_LOCK_DEBUG);
		_Swap_proxy_and_iter_unlocked(_Cont);
	}
};

class _Iterator_base12 {
public:

	inline _Iterator_base12() noexcept = default;
	inline _Iterator_base12(const _Iterator_base12& _Right) noexcept {
		*this = _Right;
	}

	inline _Iterator_base12 operator=(const _Iterator_base12& _Right) noexcept {
		_Assign_locked(_Right);
	}

	// Create conection to Container
	inline void _Adopt(const _Container_base12* _Parent) {
		_Adopt_locked(_Parent);
	}

	~_Iterator_base12() noexcept
	{
		_Orphan_me_locked();
	}

	inline const _Container_base12* _Cont() const noexcept {
		return _MyProxy->_MyCont;
	}

	_Container_proxy* _MyProxy = nullptr;
	_Iterator_base12* _MyNextIter = nullptr;
private:
	void _Adopt_locked(const _Container_base12* _Parent) {
		_STD _Lockit lock(_LOCK_DEBUG);
		_Adopt_unlocked(_Parent);
	}

	void _Assign_locked(const _Iterator_base12& _Right) {
		_STD _Lockit lock(_LOCK_DEBUG);
		_Assign_unlocked(_Right);
	}

	inline void _Orphan_me_locked()
	{
		_STD _Lockit lock(_LOCK_DEBUG);
		_Orphan_me_unlocked();
	};

	inline void _Orphan_me_unlocked() 
	{
		if (!_MyProxy) {
			return;
		}

		_Iterator_base12** _Pnext = &_MyProxy->_MyfirstIter;
		while (!_Pnext && *_Pnext != this) {
			_Pnext = &(*_Pnext)->_MyNextIter;
		}

		*_Pnext = _MyNextIter;
		_MyProxy = nullptr;
	};

	inline void _Adopt_unlocked(const _Container_base12* _Parent) {
		if (!_Parent) {
			_Orphan_me_unlocked();
			return;
		}

		_Container_proxy* _Parent_proxy = _Parent->_MyProxy;
		if (_MyProxy != _Parent_proxy) {
			if (!_MyProxy) {
				_Orphan_me_unlocked();
			}

			_MyNextIter = _Parent_proxy->_MyfirstIter;
			_Parent_proxy->_MyfirstIter = this;
			_MyProxy = _Parent_proxy;
		}
	}

	inline void _Assign_unlocked(const _Iterator_base12& _Right) {
		if (_MyProxy == _Right._MyProxy) {
			return;
		}

		if (_Right._MyProxy) {
			_Adopt_unlocked(_Right._MyProxy->_MyCont);
		}
		else {
			_Orphan_me_unlocked();
		}
	}
};


inline void _Container_base12::_Swap_proxy_and_iter_unlocked(_Container_base12& _Cont) noexcept {
	_Container_proxy* temp = _MyProxy;
	_MyProxy = _Cont._MyProxy;
	_Cont._MyProxy = temp;

	if (_MyProxy) {
		_MyProxy->_MyCont = this;
	}

	if (_Cont._MyProxy) {
		_Cont._MyProxy->_MyCont = &_Cont;
	}
}

inline void _Container_base12::_Orphan_all_unlocked() noexcept {
	if (!_MyProxy) {
		return;
	}

	for (auto _Pnext = _STD exchange(_MyProxy->_MyfirstIter, nullptr); _Pnext; _Pnext = _Pnext->_MyNextIter) {
		_Pnext->_MyProxy = nullptr;
	}
}

_VEC_END