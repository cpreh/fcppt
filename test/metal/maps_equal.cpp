//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/metal/maps_equal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(fcppt::metal::maps_equal<
                metal::map<metal::pair<int, float>, metal::pair<bool, double>>,
                metal::map<metal::pair<bool, double>, metal::pair<int, float>>>::value);

  static_assert(!fcppt::metal::maps_equal<
                metal::map<metal::pair<int, float>, metal::pair<bool, double>>,
                metal::map<metal::pair<int, float>, metal::pair<bool, float>>>::value);

  static_assert(!fcppt::metal::maps_equal<
                metal::map<metal::pair<int, float>, metal::pair<bool, double>>,
                metal::map<metal::pair<int, float>>>::value);
}
