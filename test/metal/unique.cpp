//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/metal/contains.hpp>
#include <fcppt/metal/unique.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>

int main()
{
  {
    using list = fcppt::metal::unique<metal::list<int, int>>;

    static_assert(::metal::size<list>::value == 1U);

    static_assert(fcppt::metal::contains<list, int>::value);
  }

  {
    using list = fcppt::metal::unique<metal::list<int, float>>;

    static_assert(::metal::size<list>::value == 2U);

    static_assert(fcppt::metal::contains<list, int>::value);

    static_assert(fcppt::metal::contains<list, float>::value);
  }
}
