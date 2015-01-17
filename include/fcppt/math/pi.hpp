//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_PI_HPP_INCLUDED
#define FCPPT_MATH_PI_HPP_INCLUDED

#include <fcppt/math/detail/pi.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Returns Pi for type T
\ingroup fcpptmath
\tparam T Must be a floating point type
*/
template<
	typename T
>
inline
T
pi()
{
	static_assert(
		std::is_floating_point<
			T
		>::value,
		"math::pi must return a floating point type"
	);

	return
		fcppt::math::detail::pi<
			T
		>::get();
}

}
}

#endif
