//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/metal/set/contains.hpp>
#include <fcppt/metal/set/from_list_relaxed.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>

int main()
{
  using result = fcppt::metal::set::from_list_relaxed<::metal::list<
      short, // NOLINT(google-runtime-int)
      int,
      int>>;

  static_assert(fcppt::metal::set::contains<result, int>::value, "Set does not contain int");

  static_assert(
      fcppt::metal::set::contains<
          result,
          short // NOLINT(google-runtime-int)
          >::value,
      "Set does not contain short");
}
