//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/is_invocable.hpp>
#include <fcppt/mpl/is_invocable_v.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

int main()
{
  struct F
  {
    void operator()(int) const {}
  };

  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::mpl::is_invocable<F, fcppt::mpl::list::object<int>>::value);
  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(!fcppt::mpl::is_invocable<F, fcppt::mpl::list::object<std::string>>::value);

  static_assert(fcppt::mpl::is_invocable_v<F, fcppt::mpl::list::object<int>>);
  static_assert(!fcppt::mpl::is_invocable_v<F, fcppt::mpl::list::object<std::string>>);

  F const f{};
  f(10);
}
