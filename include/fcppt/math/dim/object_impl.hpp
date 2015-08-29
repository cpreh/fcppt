//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DIM_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/assert_static_storage.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/copy.hpp>
#include <fcppt/math/detail/index_at.hpp>
#include <fcppt/math/detail/make_op_def.hpp>
#include <fcppt/math/dim/object_decl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
fcppt::math::dim::object<
	T,
	N,
	S
>::object(
	fcppt::no_init const &
)
// Don't initialize storage_
{
	FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(
		S
	);
}

FCPPT_PP_POP_WARNING

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
template<
	typename ...Args
>
fcppt::math::dim::object<
	T,
	N,
	S
>::object(
	Args const &..._args
)
:
	storage_{{
		_args...
	}}
{
	FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(
		S
	);

	static_assert(
		sizeof...(
			Args
		)
		==
		N,
		"Wrong number of parameters"
	);
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
fcppt::math::dim::object<
	T,
	N,
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
	fcppt::math::size_type N,
	typename S
>
fcppt::math::dim::object<
	T,
	N,
	S
>::object(
	object const &
)
= default;

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::dim::object<
	T,
	N,
	S
>::object(
	fcppt::math::dim::object<
		T,
		N,
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
	fcppt::math::size_type N,
	typename S
>
fcppt::math::dim::object<
	T,
	N,
	S
> &
fcppt::math::dim::object<
	T,
	N,
	S
>::operator=(
	object const &
)
= default;

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::dim::object<
	T,
	N,
	S
> &
fcppt::math::dim::object<
	T,
	N,
	S
>::operator=(
	fcppt::math::dim::object<
		T,
		N,
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
	fcppt::math::size_type N,
	typename S
>
fcppt::math::dim::object<
	T,
	N,
	S
>::~object()
{
}

#define FCPPT_MATH_DIM_OBJECT_DEFINE_OPERATOR(\
	op\
)\
FCPPT_MATH_DETAIL_MAKE_OP_DEF(\
	3,\
	(template<typename T, fcppt::math::size_type N, typename S> template<typename OtherStorage>),\
	(fcppt::math::dim::object<T, N, S>),\
	(fcppt::math::dim::object<T, N, OtherStorage>),\
	op\
)

FCPPT_MATH_DIM_OBJECT_DEFINE_OPERATOR(+=)
FCPPT_MATH_DIM_OBJECT_DEFINE_OPERATOR(-=)
FCPPT_MATH_DIM_OBJECT_DEFINE_OPERATOR(*=)
FCPPT_MATH_DIM_OBJECT_DEFINE_OPERATOR(/=)
FCPPT_MATH_DIM_OBJECT_DEFINE_OPERATOR(%=)

#undef FCPPT_MATH_DIM_OBJECT_DEFINE_OPERATOR

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
fcppt::math::dim::object<
	T,
	N,
	S
> &
fcppt::math::dim::object<
	T,
	N,
	S
>::operator*=(
	value_type const &_value
)
{
	for(
		auto &ref
		:
		storage_
	)
		ref *=
			_value;

	return
		*this;
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
fcppt::math::dim::object<
	T,
	N,
	S
> &
fcppt::math::dim::object<
	T,
	N,
	S
>::operator/=(
	value_type const &_value
)
{
	for(
		auto &ref
		:
		storage_
	)
		ref /=
			_value;

	return
		*this;
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
typename fcppt::math::dim::object<
	T,
	N,
	S
>::reference
fcppt::math::dim::object<
	T,
	N,
	S
>::operator[](
	size_type const _index
)
{
	return
		fcppt::math::detail::index_at(
			storage_,
			_index
		);
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
typename fcppt::math::dim::object<
	T,
	N,
	S
>::const_reference
fcppt::math::dim::object<
	T,
	N,
	S
>::operator[](
	size_type const _index
) const
{
	return
		fcppt::math::detail::index_at(
			storage_,
			_index
		);
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
typename fcppt::math::dim::object<
	T,
	N,
	S
>::reference
fcppt::math::dim::object<
	T,
	N,
	S
>::w()
{
	return
		fcppt::math::detail::checked_access<
			0
	>(
		*this
	);
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
typename fcppt::math::dim::object<
	T,
	N,
	S
>::const_reference
fcppt::math::dim::object<
	T,
	N,
	S
>::w() const
{
	return
		fcppt::math::detail::checked_access<
			0
		>(
			*this
		);
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
typename fcppt::math::dim::object<
	T,
	N,
	S
>::reference
fcppt::math::dim::object<
	T,
	N,
	S
>::h()
{
	return
		fcppt::math::detail::checked_access<
			1
		>(
			*this
		);
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
typename fcppt::math::dim::object<
	T,
	N,
	S
>::const_reference
fcppt::math::dim::object<
	T,
	N,
	S
>::h() const
{
	return
		fcppt::math::detail::checked_access<
			1
		>(
			*this
		);
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
typename fcppt::math::dim::object<
	T,
	N,
	S
>::reference
fcppt::math::dim::object<
	T,
	N,
	S
>::d()
{
	return
		fcppt::math::detail::checked_access<
			2
		>(
			*this
		);
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
typename fcppt::math::dim::object<
	T,
	N,
	S
>::const_reference
fcppt::math::dim::object<
	T,
	N,
	S
>::d() const
{
	return
		fcppt::math::detail::checked_access<
			2
		>(
			*this
		);
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
S &
fcppt::math::dim::object<
	T,
	N,
	S
>::storage()
{
	return
		storage_;
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
S const &
fcppt::math::dim::object<
	T,
	N,
	S
>::storage() const
{
	return
		storage_;
}

#endif
