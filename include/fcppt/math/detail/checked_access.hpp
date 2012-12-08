//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_CHECKED_ACCESS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_CHECKED_ACCESS_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/dynamic_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

// TODO: Try to unify this!

template<
	fcppt::math::size_type N,
	typename T
>
typename boost::enable_if<
	std::is_same<
		typename T::dim_wrapper,
		fcppt::math::detail::dynamic_size
	>,
	typename T::reference
>::type
checked_access(
	T &_value
)
{
	return
		_value[N];
}

template<
	fcppt::math::size_type N,
	typename T
>
typename boost::disable_if<
	std::is_same<
		typename T::dim_wrapper,
		fcppt::math::detail::dynamic_size
	>,
	typename T::reference
>::type
checked_access(
	T &_value
)
{
	typedef typename T::dim_wrapper dim_wrapper;

	static_assert(
		N < dim_wrapper::value,
		"Out of bounds operator[] access to a math type"
	);

	return
		_value[N];
}

template<
	fcppt::math::size_type N,
	typename T
>
typename boost::enable_if<
	std::is_same<
		typename T::dim_wrapper,
		fcppt::math::detail::dynamic_size
	>,
	typename T::const_reference
>::type
checked_access(
	T const &_value
)
{
	return
		_value[N];
}

template<
	fcppt::math::size_type N,
	typename T
>
typename boost::disable_if<
	std::is_same<
		typename T::dim_wrapper,
		fcppt::math::detail::dynamic_size
	>,
	typename T::const_reference
>::type
checked_access(
	T const &_value
)
{
	typedef typename T::dim_wrapper dim_wrapper;

	static_assert(
		N < dim_wrapper::value,
		"Out of bounds operator[] access to a math type"
	);

	return
		_value[N];
}

}
}
}

#endif
