//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_CHECKED_ACCESS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_CHECKED_ACCESS_HPP_INCLUDED

#include <fcppt/math/detail/dynamic_size.hpp>
#include <fcppt/math/size_type.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	size_type N,
	typename T
>
typename boost::enable_if<
	boost::is_same<
		typename T::dim_wrapper,
		detail::dynamic_size
	>,
	typename T::reference
>::type
checked_access(
	T &t
)
{
	return t[N];
}

template<
	size_type N,
	typename T
>
typename boost::disable_if<
	boost::is_same<
		typename T::dim_wrapper,
		detail::dynamic_size
	>,
	typename T::reference
>::type
checked_access(
	T &t
)
{
	typedef typename T::dim_wrapper dim_wrapper;

	BOOST_STATIC_ASSERT(
		N < dim_wrapper::value
	);

	return t[N];
}

template<
	size_type N,
	typename T
>
typename boost::enable_if<
	boost::is_same<
		typename T::dim_wrapper,
		detail::dynamic_size
	>,
	typename T::const_reference
>::type
checked_access(
	T const &t
)
{
	return t[N];
}

template<
	size_type N,
	typename T
>
typename boost::disable_if<
	boost::is_same<
		typename T::dim_wrapper,
		detail::dynamic_size
	>,
	typename T::const_reference
>::type
checked_access(
	T const &t
)
{
	typedef typename T::dim_wrapper dim_wrapper;

	BOOST_STATIC_ASSERT(
		N < dim_wrapper::value
	);

	return t[N];
}

}
}
}

#endif
