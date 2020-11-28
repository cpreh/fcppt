//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DIFFERENCE_TYPE_HPP_INCLUDED
#define FCPPT_MATH_DIFFERENCE_TYPE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
/**
\brief The difference type used for structure sizes
\ingroup fcpptmath
*/
using difference_type = std::make_signed_t<fcppt::math::size_type>;

}
}

#endif
