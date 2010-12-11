//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_CEIL_DIV_HPP_INCLUDED
#define FCPPT_MPL_CEIL_DIV_HPP_INCLUDED

#include <boost/mpl/integral_c.hpp>
#include <boost/type_traits/is_unsigned.hpp>
#include <boost/static_assert.hpp>

namespace fcppt
{
namespace mpl
{

/// Calculates Dividend / Divisor rounded towards infinity
template<
	typename T,
	T Dividend,
	T Divisor
>
struct ceil_div
:
boost::mpl::integral_c<
	T,
	Dividend
	/
	Divisor
	+
	(
		Dividend %
		Divisor
		?
			1u
		:
			0u
	)
>
{
	BOOST_STATIC_ASSERT(
		boost::is_unsigned<
			T
		>::value
	);
};

}
}

#endif
