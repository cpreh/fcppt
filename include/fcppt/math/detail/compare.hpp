//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_COMPARE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_COMPARE_HPP_INCLUDED

#include <fcppt/math/nearly_equals.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
inline
typename boost::disable_if<
	boost::is_floating_point<
		T
	>,
	bool
>::type
compare(
	T const &_a,
	T const &_b
)
{
	return _a == _b;
}

template<
	typename T
>
inline
typename boost::enable_if<
	boost::is_floating_point<
		T
	>,
	bool
>::type
compare(
	T const &_a,
	T const &_b
)
{
	return
		math::nearly_equals(
			_a,
			_b
		);
}

}
}
}

#endif
