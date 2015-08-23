//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <fcppt/math/detail/make_op_def.hpp>
#include <fcppt/math/matrix/object_decl.hpp>
#include <fcppt/math/matrix/static_storage.hpp>
#include <fcppt/math/matrix/detail/row_view_impl.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


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
template<
	typename ...Args
>
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::object(
	Args const &..._args
)
:
	storage_{{
		_args...
	}}
{
	static_assert(
		sizeof...(
			Args
		)
		==
		dim_wrapper::value,
		"Wrong number of parameters"
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
= default;

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
	object const &
)
= default;

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
>::operator*=(
	value_type const &_value
)
{
	for(
		auto &item
		:
		storage_
	)
		item *=
			_value;

	return
		*this;
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
> &
fcppt::math::matrix::object<
	T,
	N,
	M,
	S
>::operator/=(
	value_type const &_value
)
{
	for(
		auto &item
		:
		storage_
	)
		item /=
			_value;

	return
		*this;
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
			typename
			reference::storage_type(
				storage_.data(),
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
>::const_reference
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
			typename
			const_reference::storage_type(
				storage_.data(),
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
constexpr
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
constexpr
typename
fcppt::math::matrix::object<
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

#endif
