//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_MAKE_UNIFORM_ENUM_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_MAKE_UNIFORM_ENUM_HPP_INCLUDED

#include <fcppt/enum/is_object.hpp>
#include <fcppt/random/distribution/parameters/make_uniform_enum_advanced.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>
#include <fcppt/random/distribution/parameters/uniform_int_wrapper_fwd.hpp>

namespace fcppt::random::distribution::parameters
{
template <typename Enum>
inline fcppt::random::distribution::parameters::uniform_int<Enum> make_uniform_enum()
  requires(fcppt::enum_::is_object<Enum>::value)
{
  return fcppt::random::distribution::parameters::make_uniform_enum_advanced<
      fcppt::random::distribution::parameters::uniform_int_wrapper,
      Enum>();
}
}

#endif
