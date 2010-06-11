//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_BASIC_IMPL_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_BASIC_IMPL_HPP_INCLUDED

#include <fcppt/math/vector/basic_decl.hpp>
#include <fcppt/math/vector/max_ctor_params.hpp>
#include <fcppt/math/vector/normal_storage.hpp>
#include <fcppt/math/detail/array_adapter_impl.hpp>
#include <fcppt/math/detail/make_op_def.hpp>
#include <fcppt/math/detail/storage_data.hpp>
#include <fcppt/math/detail/storage_dim.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/make_variadic_constructor.hpp>
#include <fcppt/math/detail/initial_size.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <iterator>
#include <algorithm>

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::basic<T, N, S>::basic()
{}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::basic<T, N, S>::basic(
	storage_type const &storage
)
:
	storage(storage)
{}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::basic<T, N, S>::basic(
	basic const &other_
)
:
	storage(other_.storage)
{}

template<
	typename T,
	typename N,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::vector::basic<T, N, S>::basic(
	basic<
		T,
		N,
		OtherStorage
	> const &other_
)
{
	math::detail::initial_size(
		storage,
		other_.size()
	);

	std::copy(
		other_.begin(),
		other_.end(),
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
fcppt::math::vector::basic<T, N, S>::basic(
	In const beg,
	typename boost::enable_if<
		type_traits::is_iterator<
			In
		>,
		In
	>::type const end
)
{
	math::detail::initial_size(
		storage,
		std::distance(
			beg,
			end
		)
	);

	std::copy(
		beg,
		end,
		begin()
	);
}

FCPPT_MATH_DETAIL_ARRAY_ADAPTER_IMPL(
	3,
	(template<typename T, typename N, typename S>),
	(fcppt::math::vector::basic<T, N, S>)
)

FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR(
	FCPPT_MATH_VECTOR_MAX_CTOR_PARAMS,
	(5, (template<typename T, typename N, typename S> fcppt::math::vector::basic<T, N, S>::basic))
)

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::basic<T, N, S> &
fcppt::math::vector::basic<T, N, S>::operator=(
	basic const &other_
)
{
	return
		math::detail::assign(
			*this,
			other_
		);
}

template<
	typename T,
	typename N,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::vector::basic<T, N, S> &
fcppt::math::vector::basic<T, N, S>::operator=(
	basic<
		T,
		N,
		OtherStorage
	> const &other_
)
{
	return
		math::detail::assign(
			*this,
			other_
		);
}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::basic<T, N, S>::~basic()
{}

// \cond
#define FCPPT_MATH_VECTOR_BASIC_DEFINE_OPERATOR(\
	op\
)\
FCPPT_MATH_DETAIL_MAKE_OP_DEF(\
	3,\
	(template<typename T, typename N, typename S> template<typename OtherStorage>),\
	(fcppt::math::vector::basic<T, N, S>),\
	(fcppt::math::vector::basic<T, N, OtherStorage>),\
	op\
)
// \endcond

FCPPT_MATH_VECTOR_BASIC_DEFINE_OPERATOR(+=)
FCPPT_MATH_VECTOR_BASIC_DEFINE_OPERATOR(-=)
FCPPT_MATH_VECTOR_BASIC_DEFINE_OPERATOR(*=)
FCPPT_MATH_VECTOR_BASIC_DEFINE_OPERATOR(/=)
FCPPT_MATH_VECTOR_BASIC_DEFINE_OPERATOR(%=)

#undef FCPPT_MATH_VECTOR_BASIC_DEFINE_OPERATOR

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::basic<T, N, S> &
fcppt::math::vector::basic<T, N, S>::operator*=(
	value_type const &v
)
{
	for(size_type i = 0; i < size(); ++i)
		(*this)[i] *= v;
	return *this;
}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::basic<T, N, S> &
fcppt::math::vector::basic<T, N, S>::operator/=(
	value_type const &v
)
{
	for(size_type i = 0; i < size(); ++i)
		(*this)[i] /= v;
	return *this;
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::basic<T, N, S>::const_reference
fcppt::math::vector::basic<T, N, S>::operator[](
	size_type const index
) const
{
	return storage[index];
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::basic<T, N, S>::reference
fcppt::math::vector::basic<T, N, S>::operator[](
	size_type const index
)
{
	return storage[index];
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::basic<T, N, S>::pointer
fcppt::math::vector::basic<T, N, S>::data()
{
	return math::detail::storage_data(
		storage
	);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::basic<T, N, S>::const_pointer
fcppt::math::vector::basic<T, N, S>::data() const
{
	return math::detail::storage_data(
		storage
	);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::basic<T, N, S>::size_type
fcppt::math::vector::basic<T, N, S>::size() const
{
	return
		static_cast<
			size_type
		>(
			math::detail::storage_dim(
				storage
			)
		);
}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::basic<T, N, S> const
fcppt::math::vector::basic<T, N, S>::null()
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
typename fcppt::math::vector::basic<T, N, S>::reference
fcppt::math::vector::basic<T, N, S>::x()
{
	return math::detail::checked_access<0>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::basic<T, N, S>::const_reference
fcppt::math::vector::basic<T, N, S>::x() const
{
	return math::detail::checked_access<0>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::basic<T, N, S>::reference
fcppt::math::vector::basic<T, N, S>::y()
{
	return math::detail::checked_access<1>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::basic<T, N, S>::const_reference
fcppt::math::vector::basic<T, N, S>::y() const
{
	return math::detail::checked_access<1>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::basic<T, N, S>::reference
fcppt::math::vector::basic<T, N, S>::z()
{
	return math::detail::checked_access<2>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::basic<T, N, S>::const_reference
fcppt::math::vector::basic<T, N, S>::z() const
{
	return math::detail::checked_access<2>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::basic<T, N, S>::reference
fcppt::math::vector::basic<T, N, S>::w()
{
	return math::detail::checked_access<3>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::basic<T, N, S>::const_reference
fcppt::math::vector::basic<T, N, S>::w() const
{
	return math::detail::checked_access<3>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
void
fcppt::math::vector::basic<T, N, S>::resize(
	size_type const sz
)
{
	storage.resize(
		sz
	);
}

template<
	typename T,
	typename N,
	typename S
>
void
fcppt::math::vector::basic<T, N, S>::swap(
	basic &other_
)
{
	std::swap(
		storage,
		other_.storage
	);
}

template<
	typename T,
	typename N,
	typename S
>
void
fcppt::math::vector::swap(
	basic<T, N, S> &a,
	basic<T, N, S> &b
)
{
	return a.swap(b);
}

#endif
