//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TYPE_ISO_BOOST_UNITS_HPP_INCLUDED
#define FCPPT_TYPE_ISO_BOOST_UNITS_HPP_INCLUDED

#include <fcppt/type_iso/transform_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/units/quantity.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt::type_iso
{
/**
\brief Integrates boost.units with fcppt.type_iso

\ingroup fcpptboost
*/
template <typename Unit, typename Type>
struct transform<boost::units::quantity<Unit, Type>>
{
  using undecorated_type = Type;

  using decorated_type = boost::units::quantity<Unit, Type>;

  static inline decorated_type decorate(undecorated_type const &_value)
  {
    return decorated_type::from_value(_value);
  }

  static inline undecorated_type undecorate(decorated_type const &_value) { return _value.value(); }
};

}

#endif
