//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/assert_static_storage.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <fcppt/math/detail/copy.hpp>
#include <fcppt/math/detail/make_op_def.hpp>
#include <fcppt/math/matrix/object_decl.hpp>
#include <fcppt/math/matrix/row_type.hpp>
#include <fcppt/math/matrix/detail/init_storage.hpp>
#include <fcppt/math/matrix/detail/row_view_impl.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::object(
	fcppt::no_init const &
)
// Don't initialize storage_()
{
	FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(
		S
	);
}

FCPPT_PP_POP_WARNING

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
template<
	typename ...Args
>
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::object(
	Args const &..._args
)
:
	storage_(
		fcppt::math::matrix::detail::init_storage(
			std::array<
				fcppt::math::matrix::row_type<
					T,
					static_columns::value
				>,
				sizeof...(
					Args
				)
			>{{
				_args...
			}}
		)
	)
{

	FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(
		S
	);

	static_assert(
		sizeof...(
			Args
		)
		==
		static_rows::value,
		"Wrong number of rows"
	);
}

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
fcppt::math::matrix::object<
	T,
	R,
	C,
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
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::object(
	object const &
)
= default;

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::object(
	fcppt::math::matrix::object<
		T,
		R,
		C,
		OtherStorage
	> const &_other
)
:
	storage_(
		fcppt::math::detail::copy<
			S
		>(
			_other
		)
	)
{
}

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
> &
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::operator=(
	object const &
)
= default;

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
> &
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::operator=(
	fcppt::math::matrix::object<
		T,
		R,
		C,
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
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::~object()
{
}

#define FCPPT_MATH_MATRIX_OBJECT_DEFINE_OPERATOR(\
	op\
)\
FCPPT_MATH_DETAIL_MAKE_OP_DEF(\
	4,\
	(template<typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S> template<typename OtherStorage>),\
	(fcppt::math::matrix::object<T, R, C, S>),\
	(fcppt::math::matrix::object<T, R, C, OtherStorage>),\
	op\
)

FCPPT_MATH_MATRIX_OBJECT_DEFINE_OPERATOR(+=)
FCPPT_MATH_MATRIX_OBJECT_DEFINE_OPERATOR(-=)

#undef FCPPT_MATH_MATRIX_OBJECT_DEFINE_OPERATOR

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
> &
fcppt::math::matrix::object<
	T,
	R,
	C,
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
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
> &
fcppt::math::matrix::object<
	T,
	R,
	C,
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
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
typename
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::reference
fcppt::math::matrix::object<
	T,
	R,
	C,
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
				this->columns()
			)
		);
}

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
typename
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::const_reference
fcppt::math::matrix::object<
	T,
	R,
	C,
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
				this->columns()
			)
		);
}

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
constexpr
typename
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::size_type
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::rows()
{
	return
		R;
}

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
constexpr
typename
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::size_type
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::columns()
{
	return
		C;
}

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
S &
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::storage()
{
	return
		storage_;
}

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
S const &
fcppt::math::matrix::object<
	T,
	R,
	C,
	S
>::storage() const
{
	return
		storage_;
}

#endif
