//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_CHECKED_ACCESS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_CHECKED_ACCESS_HPP_INCLUDED

#include <fcppt/static_assert_expression.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/dynamic_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


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
	T &_value
)
{
	return
		_value[N];
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
	T &_value
)
{
	typedef typename T::dim_wrapper dim_wrapper;

	FCPPT_STATIC_ASSERT_EXPRESSION(
		N < dim_wrapper::value
	);

	return
		_value[N];
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
	T const &_value
)
{
	return
		_value[N];
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
	T const &_value
)
{
	typedef typename T::dim_wrapper dim_wrapper;

	FCPPT_STATIC_ASSERT_EXPRESSION(
		N < dim_wrapper::value
	);

	return
		_value[N];
}

}
}
}

#endif
