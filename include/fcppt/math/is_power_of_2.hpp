//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_IS_POWER_OF_2_HPP_INCLUDED
#define FCPPT_MATH_IS_POWER_OF_2_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Checks if a number is a power of two
\ingroup fcpptmath
\tparam T Must be an unsigned integral type

If you need to check whether a signed integral type is a power of two, convert
it to its unsigned counterpart before checking.
*/
template<
	typename T
>
inline
constexpr
bool
is_power_of_2(
	T const x
)
{
	static_assert(
		std::is_unsigned<
			T
		>::value,
		"is_power_of_2 can only be used on unsigned types"
	);

	return x && !(x & (x - 1));
}

}
}

#endif
