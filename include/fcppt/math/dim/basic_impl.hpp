//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_BASIC_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DIM_BASIC_IMPL_HPP_INCLUDED

#include <fcppt/math/detail/array_adapter_impl.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/make_op_def.hpp>
#include <fcppt/math/detail/make_variadic_constructor.hpp>
#include <fcppt/math/detail/storage_data.hpp>
#include <fcppt/math/detail/storage_dim.hpp>
#include <fcppt/math/dim/basic_decl.hpp>
#include <fcppt/math/dim/max_ctor_params.hpp>
#include <fcppt/math/dim/normal_storage.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	typename N,
	typename S
>
fcppt::math::dim::basic<T, N, S>::basic()
{}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::dim::basic<T, N, S>::basic(
	storage_type const &_storage
)
:
	storage_(_storage)
{}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::dim::basic<T, N, S>::basic(
	basic const &_other
)
:
	storage_(_other.storage_)
{}

template<
	typename T,
	typename N,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::dim::basic<T, N, S>::basic(
	basic<
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
fcppt::math::dim::basic<T, N, S>::basic(
	In const _begin,
	typename boost::enable_if<
		type_traits::is_iterator<
			In
		>,
		In
	>::type const _end
)
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

FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL(
	3,
	(template<typename T, typename N, typename S>),
	(fcppt::math::dim::basic<T, N, S>)
)

FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR(
	FCPPT_MATH_DIM_MAX_CTOR_PARAMS,
	(5, (template<typename T, typename N, typename S> fcppt::math::dim::basic<T, N, S>::basic))
)

// Doxygen says: warning: no uniquely matching class member found for ...
/// \cond FCPPT_DOXYGEN_DEBUG 
template<
	typename T,
	typename N,
	typename S
>
fcppt::math::dim::basic<T, N, S> &
fcppt::math::dim::basic<T, N, S>::operator=(
	basic const &_other
)
{
	storage_ = _other.storage_;

	return *this;
}
/// \endcond

template<
	typename T,
	typename N,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::dim::basic<T, N, S> &
fcppt::math::dim::basic<T, N, S>::operator=(
	basic<
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
fcppt::math::dim::basic<T, N, S>::~basic()
{}

// \cond FCPPT_DOXYGEN_DEBUG
#define FCPPT_MATH_DIM_BASIC_DEFINE_OPERATOR(\
	op\
)\
FCPPT_MATH_DETAIL_MAKE_OP_DEF(\
	3,\
	(template<typename T, typename N, typename S> template<typename OtherStorage>),\
	(fcppt::math::dim::basic<T, N, S>),\
	(fcppt::math::dim::basic<T, N, OtherStorage>),\
	op\
)
// \endcond

FCPPT_MATH_DIM_BASIC_DEFINE_OPERATOR(+=)
FCPPT_MATH_DIM_BASIC_DEFINE_OPERATOR(-=)
FCPPT_MATH_DIM_BASIC_DEFINE_OPERATOR(*=)
FCPPT_MATH_DIM_BASIC_DEFINE_OPERATOR(/=)
FCPPT_MATH_DIM_BASIC_DEFINE_OPERATOR(%=)

#undef FCPPT_MATH_DIM_BASIC_DEFINE_OPERATOR

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::dim::basic<T, N, S> &
fcppt::math::dim::basic<T, N, S>::operator*=(
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
fcppt::math::dim::basic<T, N, S> &
fcppt::math::dim::basic<T, N, S>::operator/=(
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
typename fcppt::math::dim::basic<T, N, S>::reference
fcppt::math::dim::basic<T, N, S>::operator[](
	size_type const index
)
{
	return storage_[index];
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::const_reference
fcppt::math::dim::basic<T, N, S>::operator[](
	size_type const index
) const
{
	return storage_[index];
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::pointer
fcppt::math::dim::basic<T, N, S>::data()
{
	return
		math::detail::storage_data(
			storage_
		);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::const_pointer
fcppt::math::dim::basic<T, N, S>::data() const
{
	return
		math::detail::storage_data(
			storage_
		);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::size_type
fcppt::math::dim::basic<T, N, S>::size() const
{
	return
		static_cast<
			size_type
		>(
			math::detail::storage_dim(
				storage_
			)
		);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::reference
fcppt::math::dim::basic<T, N, S>::w()
{
	return math::detail::checked_access<0>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::const_reference
fcppt::math::dim::basic<T, N, S>::w() const
{
	return math::detail::checked_access<0>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::reference
fcppt::math::dim::basic<T, N, S>::h()
{
	return math::detail::checked_access<1>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::const_reference
fcppt::math::dim::basic<T, N, S>::h() const
{
	return math::detail::checked_access<1>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::reference
fcppt::math::dim::basic<T, N, S>::d()
{
	return math::detail::checked_access<2>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::const_reference
fcppt::math::dim::basic<T, N, S>::d() const
{
	return math::detail::checked_access<2>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::value_type
fcppt::math::dim::basic<T, N, S>::content() const
{
	return
		std::accumulate(
			begin(),
			end(),
			static_cast<
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
fcppt::math::dim::basic<T, N, S> const
fcppt::math::dim::basic<T, N, S>::null()
{
	basic<
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
void
fcppt::math::dim::basic<T, N, S>::swap(
	basic &_other
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
fcppt::math::dim::swap(
	basic<T, N, S> &_a,
	basic<T, N, S> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
