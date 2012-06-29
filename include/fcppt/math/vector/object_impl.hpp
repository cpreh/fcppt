//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/math/detail/array_adapter_impl.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/index_at.hpp>
#include <fcppt/math/detail/initial_size.hpp>
#include <fcppt/math/detail/make_op_def.hpp>
#include <fcppt/math/detail/make_variadic_constructor.hpp>
#include <fcppt/math/vector/max_ctor_params.hpp>
#include <fcppt/math/vector/normal_storage.hpp>
#include <fcppt/math/vector/object_decl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<T, N, S>::object()
// Don't initialize storage_
{
}

FCPPT_PP_POP_WARNING

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<T, N, S>::object(
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
fcppt::math::vector::object<T, N, S>::object(
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
fcppt::math::vector::object<T, N, S>::object(
	object<
		T,
		N,
		OtherStorage
	> const &_other
)
// Don't initialize storage_
{
	math::detail::initial_size(
		storage_,
		_other.size()
	);

	std::copy(
		_other.begin(),
		_other.end(),
		begin()
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
fcppt::math::vector::object<T, N, S>::object(
	In const _begin,
	typename boost::enable_if<
		type_traits::is_iterator<
			In
		>,
		In
	>::type const _end
)
// Don't initialize storage_
{
	math::detail::initial_size(
		storage_,
		std::distance(
			_begin,
			_end
		)
	);

	std::copy(
		_begin,
		_end,
		begin()
	);
}

FCPPT_PP_POP_WARNING

FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL(
	3,
	(template<typename T, typename N, typename S>),
	(fcppt::math::vector::object<T, N, S>)
)

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR(
	FCPPT_MATH_VECTOR_MAX_CTOR_PARAMS,
	(5, (template<typename T, typename N, typename S> fcppt::math::vector::object<T, N, S>::object))
)

FCPPT_PP_POP_WARNING

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<T, N, S> &
fcppt::math::vector::object<T, N, S>::operator=(
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
fcppt::math::vector::object<T, N, S> &
fcppt::math::vector::object<T, N, S>::operator=(
	object<
		T,
		N,
		OtherStorage
	> const &_other
)
{
	math::detail::initial_size(
		storage_,
		_other.size()
	);

	return
		math::detail::assign(
			*this,
			_other
		);
}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<T, N, S>::~object()
{}

// \cond FCPPT_DOXYGEN_DEBUG
#define FCPPT_MATH_VECTOR_OBJECT_DEFINE_OPERATOR(\
	op\
)\
FCPPT_MATH_DETAIL_MAKE_OP_DEF(\
	3,\
	(template<typename T, typename N, typename S> template<typename OtherStorage>),\
	(fcppt::math::vector::object<T, N, S>),\
	(fcppt::math::vector::object<T, N, OtherStorage>),\
	op\
)
// \endcond

FCPPT_MATH_VECTOR_OBJECT_DEFINE_OPERATOR(+=)
FCPPT_MATH_VECTOR_OBJECT_DEFINE_OPERATOR(-=)
FCPPT_MATH_VECTOR_OBJECT_DEFINE_OPERATOR(*=)
FCPPT_MATH_VECTOR_OBJECT_DEFINE_OPERATOR(/=)
FCPPT_MATH_VECTOR_OBJECT_DEFINE_OPERATOR(%=)

#undef FCPPT_MATH_VECTOR_OBJECT_DEFINE_OPERATOR

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<T, N, S> &
fcppt::math::vector::object<T, N, S>::operator*=(
	value_type const &_value
)
{
	for(size_type i = 0; i < size(); ++i)
		(*this)[i] *= _value;
	return *this;
}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<T, N, S> &
fcppt::math::vector::object<T, N, S>::operator/=(
	value_type const &_value
)
{
	for(size_type i = 0; i < size(); ++i)
		(*this)[i] /= _value;
	return *this;
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::object<T, N, S>::const_reference
fcppt::math::vector::object<T, N, S>::operator[](
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
typename fcppt::math::vector::object<T, N, S>::reference
fcppt::math::vector::object<T, N, S>::operator[](
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
fcppt::math::vector::object<T, N, S> const
fcppt::math::vector::object<T, N, S>::null()
{
	object<
		T,
		N,
		typename normal_storage<
			T,
			N
		>::type
	> ret;

	for(
		size_type i = 0;
		i < N::value;
		++i
	)
		ret[i] = static_cast<value_type>(0);
	return ret;
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::object<T, N, S>::reference
fcppt::math::vector::object<T, N, S>::x()
{
	return math::detail::checked_access<0>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::object<T, N, S>::const_reference
fcppt::math::vector::object<T, N, S>::x() const
{
	return math::detail::checked_access<0>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::object<T, N, S>::reference
fcppt::math::vector::object<T, N, S>::y()
{
	return math::detail::checked_access<1>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::object<T, N, S>::const_reference
fcppt::math::vector::object<T, N, S>::y() const
{
	return math::detail::checked_access<1>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::object<T, N, S>::reference
fcppt::math::vector::object<T, N, S>::z()
{
	return math::detail::checked_access<2>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::object<T, N, S>::const_reference
fcppt::math::vector::object<T, N, S>::z() const
{
	return math::detail::checked_access<2>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::object<T, N, S>::reference
fcppt::math::vector::object<T, N, S>::w()
{
	return math::detail::checked_access<3>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::object<T, N, S>::const_reference
fcppt::math::vector::object<T, N, S>::w() const
{
	return math::detail::checked_access<3>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
void
fcppt::math::vector::object<T, N, S>::swap(
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
void
fcppt::math::vector::swap(
	object<T, N, S> &_a,
	object<T, N, S> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
