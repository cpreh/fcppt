//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_LOG2_HPP_INCLUDED
#define FCPPT_MATH_LOG2_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Calculates \f$\log_2(x)\f$ for unsigned types (using a loop)
\ingroup fcpptmath
\tparam T Must be an unsigned integral type
\warning
Behaviour is undefined if \p x is 0.
*/
template<
	typename T
>
inline
typename boost::enable_if<
	std::is_unsigned<
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
