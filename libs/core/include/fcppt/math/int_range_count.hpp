//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_INT_RANGE_COUNT_HPP_INCLUDED
#define FCPPT_MATH_INT_RANGE_COUNT_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/int_range.hpp>
#include <fcppt/math/size_type.hpp>

namespace fcppt::math
{
/**
\brief A static int range starting at 0

\ingroup fcpptmath
*/
template <fcppt::math::size_type Count>
using int_range_count = fcppt::math::int_range<fcppt::literal<fcppt::math::size_type>(0U), Count>;

}

#endif
