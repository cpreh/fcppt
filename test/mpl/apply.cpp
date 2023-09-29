//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/apply.hpp>
#include <fcppt/mpl/apply_v.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::mpl::apply<fcppt::mpl::lambda<std::is_integral>,int>::value);
  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::mpl::apply<fcppt::mpl::lambda<std::is_same>,int,int>::value);

  static_assert(fcppt::mpl::apply_v<fcppt::mpl::lambda<std::is_integral>,int>);
  static_assert(fcppt::mpl::apply_v<fcppt::mpl::lambda<std::is_same>,int,int>);
}
