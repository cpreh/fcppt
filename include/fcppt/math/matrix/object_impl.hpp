//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/math/detail/array_adapter_impl.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <fcppt/math/detail/default_storage.hpp>
#include <fcppt/math/detail/make_op_def.hpp>
#include <fcppt/math/detail/make_variadic_constructor.hpp>
#include <fcppt/math/matrix/object_decl.hpp>
#include <fcppt/math/matrix/static_storage.hpp>
#include <fcppt/math/matrix/detail/row_view_impl.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/is_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::object()
:
	storage_(
		fcppt::math::detail::default_storage<
			fcppt::math::matrix::static_storage<
				T,
				N,
				M
			>
		>()
	)
{
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::object(
	fcppt::no_init const &
)
// Don't initialize storage_()
{
}

FCPPT_PP_POP_WARNING

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::object(
	storage_type const &_storage
)
:
	storage_(
		_storage
	)
{
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::object(
	object const &_other
)
:
	storage_(
		_other.storage_
	)
{
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	typename N,
	typename M,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::object(
	fcppt::math::matrix::object<
		T,
		N,
		M,
		OtherStorage
	> const &_other
)
// Don't initialize storage_()
{
	std::copy(
		_other.begin(),
		_other.end(),
		this->begin()
	);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
template<
	typename In
>
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::object(
	In const _begin,
	typename std::enable_if<
		fcppt::type_traits::is_iterator<
			In
		>::value,
		In
	>::type const _end
)
// Don't initialize storage_()
{
	std::copy(
		_begin,
		_end,
		this->begin()
	);
}

FCPPT_PP_POP_WARNING

FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL(
	4,
	(template<typename T, typename N, typename M, typename S>),
	(fcppt::math::matrix::object<T, N, M, S>)
)

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR(
	FCPPT_MATH_MATRIX_MAX_CTOR_PARAMS,
	(7, (template<typename T, typename N, typename M, typename S> fcppt::math::matrix::object<T, N, M, S>::object))
)

FCPPT_PP_POP_WARNING

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
> &
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::operator=(
	object const &_other
)
{
	storage_ = _other.storage_;

	return *this;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
> &
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::operator=(
	fcppt::math::matrix::object<
		T,
		N,
		M,
		OtherStorage
	> const &_other
)
{
	return
		fcppt::math::detail::assign(
			*this,
			_other
		);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::~object()
{
}

#define FCPPT_MATH_MATRIX_OBJECT_DEFINE_OPERATOR(\
	op\
)\
FCPPT_MATH_DETAIL_MAKE_OP_DEF(\
	4,\
	(template<typename T, typename N, typename M, typename S> template<typename OtherStorage>),\
	(fcppt::math::matrix::object<T, N, M, S>),\
	(fcppt::math::matrix::object<T, N, M, OtherStorage>),\
	op\
)

FCPPT_MATH_MATRIX_OBJECT_DEFINE_OPERATOR(+=)
FCPPT_MATH_MATRIX_OBJECT_DEFINE_OPERATOR(-=)

#undef FCPPT_MATH_MATRIX_OBJECT_DEFINE_OPERATOR

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<T, N, M, S> &
fcppt::math::matrix::object<T, N, M, S>::operator*=(
	value_type const &_value
)
{
	for(
		auto &item : *this
	)
		item *= _value;

	return *this;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<T, N, M, S> &
fcppt::math::matrix::object<T, N, M, S>::operator/=(
	value_type const &_value
)
{
	for(
		auto &item : *this
	)
		item /= _value;

	return *this;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::reference
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::operator[](
	size_type const _j
)
{
	return
		reference(
			typename reference::storage_type(
				this->data(),
				_j,
				this->columns(),
				this->rows()
			)
		);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::const_reference const
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::operator[](
	size_type const _j
) const
{
	return
		const_reference(
			typename const_reference::storage_type(
				this->data(),
				_j,
				this->columns(),
				this->rows()
			)
		);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::size_type
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::rows()
{
	return
		M::value;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::size_type
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::columns()
{
	return
		N::value;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<
	T,
	N,
	M,
	fcppt::math::matrix::static_storage<
		T,
		N,
		M
	>
> const
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::identity()
{
	fcppt::math::matrix::object<
		T,
		N,
		M,
		fcppt::math::matrix::static_storage<
			T,
			N,
			M
		>
	> ret{
		fcppt::no_init()
	};

	for(
		size_type i = 0; i < object::rows(); ++i
	)
		for(
			size_type j = 0; j < object::columns(); ++j
		)
			ret[i][j] =
				i == j
				? fcppt::literal<T>(1)
				: fcppt::literal<T>(0);

	return ret;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
void
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::swap(
	object &_other
)
{
	std::swap(
		storage_,
		_other.storage_
	);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
S const &
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::storage() const
{
	return
		storage_;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
void
fcppt::math::matrix::swap(
	fcppt::math::matrix::object<
		T,
		N,
		M,
		S
	> &_a,
	fcppt::math::matrix::object<
		T,
		N,
		M,
		S
	> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
