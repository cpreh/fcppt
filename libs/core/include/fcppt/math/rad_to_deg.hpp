//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_RAD_TO_DEG_HPP_INCLUDED
#define FCPPT_MATH_RAD_TO_DEG_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/pi.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Transforms radians into degrees
\ingroup fcpptmath
\tparam T A floating point type
*/
template<
	typename T
>
inline
T
rad_to_deg(
	T const _rad
)
{
	static_assert(
		std::is_floating_point_v<
			T
		>,
		"rad_to_deg can only be used on floating point types"
	);

	return
		_rad
		*
		fcppt::literal<T>(180) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		/
		fcppt::math::pi<T>();
}

}
}

#endif
