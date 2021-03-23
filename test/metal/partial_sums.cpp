//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/metal/partial_sums.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  using vec = metal::numbers<3, 4, 5>;

  using result = fcppt::metal::partial_sums<vec>;

  static_assert(std::is_same_v<result, metal::numbers<0, 3, 7, 12>>);
}
