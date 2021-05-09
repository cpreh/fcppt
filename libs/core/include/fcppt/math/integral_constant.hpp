//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_INTEGRAL_CONSTANT_HPP_INCLUDED
#define FCPPT_MATH_INTEGRAL_CONSTANT_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{

template<fcppt::math::size_type N>
using integral_constant = std::integral_constant<fcppt::math::size_type, N>;

}
}

#endif
