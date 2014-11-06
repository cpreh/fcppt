//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DIM_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/static_storage.hpp>
#include <fcppt/math/detail/array_adapter_impl.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/default_storage.hpp>
#include <fcppt/math/detail/index_at.hpp>
#include <fcppt/math/detail/make_op_def.hpp>
#include <fcppt/math/detail/make_variadic_constructor.hpp>
#include <fcppt/math/detail/null_storage.hpp>
#include <fcppt/math/dim/max_ctor_params.hpp>
#include <fcppt/math/dim/object_decl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/is_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <algorithm>
#include <functional>
#include <numeric>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	typename N,
	typename S
>
fcppt::math::dim::object<
	T,
	N,
	S
>::object()
:
	storage_(
		fcppt::math::detail::default_storage<
			fcppt::math::static_storage<
				T,
				N
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
}

FCPPT_PP_POP_WARNING

template<
	typename T,
	typename N,
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
	typename N,
	typename S
>
fcppt::math::dim::object<
	T,
	N,
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
// Don't initialize storage_
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
	typename S
>
template<
	typename In
>
fcppt::math::dim::object<
	T,
	N,
	S
>::object(
	In const _begin,
	typename boost::enable_if<
		fcppt::type_traits::is_iterator<
			In
		>,
		In
	>::type const _end
)
// Don't initialize storage_
{
	std::copy(
		_begin,
		_end,
		this->begin()
	);
}

FCPPT_PP_POP_WARNING

FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL(
	3,
	(template<typename T, typename N, typename S>),
	(fcppt::math::dim::object<T, N, S>)
)

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR(
	FCPPT_MATH_DIM_MAX_CTOR_PARAMS,
	(5, (template<typename T, typename N, typename S> fcppt::math::dim::object<T, N, S>::object))
)

FCPPT_PP_POP_WARNING

template<
	typename T,
	typename N,
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
	object const &_other
)
{
	storage_ = _other.storage_;

	return *this;
}

template<
	typename T,
	typename N,
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
	typename N,
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
	(template<typename T, typename N, typename S> template<typename OtherStorage>),\
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
	typename N,
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
		auto &ref : *this
	)
		ref *= _value;

	return *this;
}

template<
	typename T,
	typename N,
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
		auto &ref : *this
	)
		ref /= _value;

	return *this;
}

template<
	typename T,
	typename N,
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
			this->begin(),
			_index
		);
}

template<
	typename T,
	typename N,
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
			this->begin(),
			_index
		);
}

template<
	typename T,
	typename N,
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
	typename N,
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
	typename N,
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
	typename N,
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
	typename N,
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
	typename N,
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
	typename N,
	typename S
>
typename fcppt::math::dim::object<
	T,
	N,
	S
>::value_type
fcppt::math::dim::object<
	T,
	N,
	S
>::content() const
{
	return
		std::accumulate(
			this->begin(),
			this->end(),
			fcppt::literal<
				value_type
			>(
				1
			),
			std::multiplies<
				value_type
			>()
		);
}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::dim::object<
	T,
	N,
	fcppt::math::static_storage<
		T,
		N
	>
> const
fcppt::math::dim::object<
	T,
	N,
	S
>::null()
{
	return
		object(
			fcppt::math::detail::null_storage<
				fcppt::math::static_storage<
					T,
					N
				>
			>()
		);
}

template<
	typename T,
	typename N,
	typename S
>
void
fcppt::math::dim::object<
	T,
	N,
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

template<
	typename T,
	typename N,
	typename S
>
void
fcppt::math::dim::swap(
	fcppt::math::dim::object<
		T,
		N,
		S
	> &_left,
	fcppt::math::dim::object<
		T,
		N,
		S
	> &_right
)
{
	_left.swap(
		_right
	);
}

#endif
