//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_SIGNUM_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_SIGNUM_HPP_INCLUDED

#include <fcppt/math/null.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_unsigned.hpp>

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
	boost::is_unsigned<
		T
	>,
	T
>::type
signum(
	T const t
)
{
	T const null_(
		math::null<T>()
	);

	if (t > null_)
		return static_cast<T>(1);

	if (t < null_)
		return static_cast<T>(-1);

	return null_;
}

template<
	typename T
>
inline
typename boost::enable_if<
	boost::is_unsigned<
		T
	>,
	T
>::type
signum(
	T const t
)
{
	T const null_(
		math::null<T>()
	);

	return
		t != null_
		?
			static_cast<T>(1)
		:
			null_;
}

}
}
}

#endif
