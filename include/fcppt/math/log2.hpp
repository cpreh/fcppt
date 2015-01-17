//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_LOG2_HPP_INCLUDED
#define FCPPT_MATH_LOG2_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
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
T
log2(
	T const x
)
{
	static_assert(
		std::is_unsigned<
			T
		>::value,
		"log2 can only be used on unsigned types"
	);

	T r(1);

	while((x >> r) != 0)
		++r;
	return --r;
}

}
}

#endif
