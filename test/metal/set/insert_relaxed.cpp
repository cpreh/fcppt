//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/metal/set/contains.hpp>
#include <fcppt/metal/set/insert_relaxed.hpp>
#include <fcppt/metal/set/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  using set = fcppt::metal::set::make<
      short, // NOLINT(google-runtime-int)
      int>;

  static_assert(std::is_same_v<
                fcppt::metal::set::insert_relaxed<
                    set,
                    short // NOLINT(google-runtime-int)
                    >,
                set>);

  static_assert(fcppt::metal::set::contains<
                fcppt::metal::set::insert_relaxed<
                    set,
                    long // NOLINT(google-runtime-int)
                    >,
                long // NOLINT(google-runtime-int)
                >::value);
}
