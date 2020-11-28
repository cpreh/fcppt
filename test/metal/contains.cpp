//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/not.hpp>
#include <fcppt/metal/contains.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>

int main()
{
  using list = metal::list<int, bool>;

  static_assert(fcppt::metal::contains<list, int>::value);

  static_assert(fcppt::metal::contains<list, bool>::value);

  static_assert(fcppt::not_(fcppt::metal::contains<list, float>::value));
}
