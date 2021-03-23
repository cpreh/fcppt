//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_MAKE_UNIFORM_ENUM_ADVANCED_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_MAKE_UNIFORM_ENUM_ADVANCED_HPP_INCLUDED

#include <fcppt/cast/int_to_enum.hpp>
#include <fcppt/enum/max_value.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>
#include <fcppt/random/distribution/parameters/uniform_int_wrapper.hpp>
#include <fcppt/type_iso/enum.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace random
{
namespace distribution
{
namespace parameters
{
template <typename Distribution, typename Enum>
fcppt::random::distribution::parameters::uniform_int<Enum, Distribution>
make_uniform_enum_advanced()
{
  static_assert(
      std::is_enum_v<Enum>, "make_uniform_enum_advanced can only be used for enumeration types");

  using param_type = fcppt::random::distribution::parameters::uniform_int<Enum, Distribution>;

  return param_type(
      typename param_type::min(fcppt::cast::int_to_enum<Enum>(0U)),
      typename param_type::max(fcppt::enum_::max_value<Enum>::value));
}

}
}
}
}

#endif
