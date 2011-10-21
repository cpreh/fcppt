//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_LOG_HPP_INCLUDED
#define FCPPT_MATH_LOG_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_unsigned.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/// Calculates \f$\log_2(x)\f$ for unsigned types (using a loop)
/**
 * @tparam T must be unsigned
 * @return - If x is 0 the result is undefined
*/
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
log2(
	T const x
)
{
	T r(1);

	while((x >> r) != 0)
		++r;
	return --r;
}

}
}

#endif
