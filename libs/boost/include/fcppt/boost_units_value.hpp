//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_BOOST_UNITS_VALUE_HPP_INCLUDED
#define FCPPT_BOOST_UNITS_VALUE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/units/quantity.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Converts a boost unit to its value

\ingroup fcpptboost
*/
struct boost_units_value
{
  template <typename Unit, typename Type>
  Type operator()(boost::units::quantity<Unit, Type> const &_unit) const
  {
    return _unit.value();
  }
};

}

#endif
