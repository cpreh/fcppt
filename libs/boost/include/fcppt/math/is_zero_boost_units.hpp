//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_IS_ZERO_BOOST_UNITS_HPP_INCLUDED
#define FCPPT_MATH_IS_ZERO_BOOST_UNITS_HPP_INCLUDED

#include <fcppt/math/is_zero.hpp>
#include <fcppt/math/is_zero_impl_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/units/quantity.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math
{
/**
\brief Integrates boost.units with #fcppt::math::is_zero.

\ingroup fcpptboost
*/
template <typename Unit, typename Type>
struct is_zero_impl<boost::units::quantity<Unit, Type>>
{
  static bool get(boost::units::quantity<Unit, Type> const &_value)
  {
    return fcppt::math::is_zero(_value.value());
  }
};

}

#endif
