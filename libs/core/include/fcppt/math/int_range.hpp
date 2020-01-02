//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_INT_RANGE_HPP_INCLUDED
#define FCPPT_MATH_INT_RANGE_HPP_INCLUDED

#include <fcppt/algorithm/loop_break_metal.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/metal/interval.hpp>


namespace fcppt
{
namespace math
{

/**
\brief A static int range

\ingroup fcpptmath
*/
template<
	fcppt::math::size_type Start,
	fcppt::math::size_type End
>
using
int_range
=
fcppt::metal::interval<
	fcppt::math::size_type,
	Start,
	End
>;

}
}

#endif
