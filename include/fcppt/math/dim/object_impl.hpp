//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DIM_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/math/detail/array_adapter_impl.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/make_op_def.hpp>
#include <fcppt/math/detail/make_variadic_constructor.hpp>
#include <fcppt/math/detail/storage_data.hpp>
#include <fcppt/math/detail/storage_dim.hpp>
#include <fcppt/math/dim/max_ctor_params.hpp>
#include <fcppt/math/dim/normal_storage.hpp>
#include <fcppt/math/dim/object_decl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <fcppt/config/external_end.hpp>

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::dim::object<T, N, S>::object()
// Don't initialize storage_
{
}

FCPPT_PP_POP_WARNING

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::dim::object<T, N, S>::object(
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
fcppt::math::dim::object<T, N, S>::object(
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
fcppt::math::dim::object<T, N, S>::object(
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
fcppt::math::dim::object<T, N, S>::object(
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
	(fcppt::math::dim::object<T, N, S>)
)

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR(
	FCPPT_MATH_DIM_MAX_CTOR_PARAMS,
	(5, (template<typename T, typename N, typename S> fcppt::math::dim::object<T, N, S>::object))
)

FCPPT_PP_POP_WARNING

// Doxygen says: warning: no uniquely matching class member found for ...
/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename T,
	typename N,
	typename S
>
fcppt::math::dim::object<T, N, S> &
fcppt::math::dim::object<T, N, S>::operator=(
	object const &_other
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
fcppt::math::dim::object<T, N, S> &
fcppt::math::dim::object<T, N, S>::operator=(
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
fcppt::math::dim::object<T, N, S>::~object()
{}

// \cond FCPPT_DOXYGEN_DEBUG
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
// \endcond

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
fcppt::math::dim::object<T, N, S> &
fcppt::math::dim::object<T, N, S>::operator*=(
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
fcppt::math::dim::object<T, N, S> &
fcppt::math::dim::object<T, N, S>::operator/=(
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
typename fcppt::math::dim::object<T, N, S>::reference
fcppt::math::dim::object<T, N, S>::operator[](
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
typename fcppt::math::dim::object<T, N, S>::const_reference
fcppt::math::dim::object<T, N, S>::operator[](
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
typename fcppt::math::dim::object<T, N, S>::pointer
fcppt::math::dim::object<T, N, S>::data()
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
typename fcppt::math::dim::object<T, N, S>::const_pointer
fcppt::math::dim::object<T, N, S>::data() const
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
typename fcppt::math::dim::object<T, N, S>::size_type
fcppt::math::dim::object<T, N, S>::size() const
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
typename fcppt::math::dim::object<T, N, S>::reference
fcppt::math::dim::object<T, N, S>::w()
{
	return math::detail::checked_access<0>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::object<T, N, S>::const_reference
fcppt::math::dim::object<T, N, S>::w() const
{
	return math::detail::checked_access<0>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::object<T, N, S>::reference
fcppt::math::dim::object<T, N, S>::h()
{
	return math::detail::checked_access<1>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::object<T, N, S>::const_reference
fcppt::math::dim::object<T, N, S>::h() const
{
	return math::detail::checked_access<1>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::object<T, N, S>::reference
fcppt::math::dim::object<T, N, S>::d()
{
	return math::detail::checked_access<2>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::object<T, N, S>::const_reference
fcppt::math::dim::object<T, N, S>::d() const
{
	return math::detail::checked_access<2>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::object<T, N, S>::value_type
fcppt::math::dim::object<T, N, S>::content() const
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
fcppt::math::dim::object<T, N, S> const
fcppt::math::dim::object<T, N, S>::null()
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
void
fcppt::math::dim::object<T, N, S>::swap(
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
fcppt::math::dim::swap(
	object<T, N, S> &_a,
	object<T, N, S> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
