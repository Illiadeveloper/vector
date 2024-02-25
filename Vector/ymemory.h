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
_VEC_END