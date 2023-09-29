//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/not.hpp>
#include <fcppt/parse/int.hpp>
#include <fcppt/parse/skipper/epsilon.hpp>
#include <fcppt/parse/skipper/is_skipper.hpp>
#include <fcppt/parse/skipper/is_skipper_v.hpp>

int main()
{
  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::parse::skipper::is_skipper<fcppt::parse::skipper::epsilon>::value);

  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::not_(fcppt::parse::skipper::is_skipper<fcppt::parse::int_<int>>::value));

  static_assert(fcppt::parse::skipper::is_skipper_v<fcppt::parse::skipper::epsilon>);

  static_assert(fcppt::not_(fcppt::parse::skipper::is_skipper_v<fcppt::parse::int_<int>>));
}
