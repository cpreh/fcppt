//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/metal/max_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
using size_type = std::size_t;

template <size_type Size>
using static_size = std::integral_constant<size_type, Size>;

}

int main()
{
  static_assert(
      std::is_same_v<
          fcppt::metal::max_value<metal::list<static_size<5U>, static_size<7U>, static_size<3U>>>,
          static_size<7U>>);
}
