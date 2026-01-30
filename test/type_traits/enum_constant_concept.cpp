//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/type_traits/enum_constant_concept.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
enum class my_enum : std::uint8_t
{
  test
};
}
int main()
{
  static_assert(fcppt::type_traits::enum_constant_concept<std::integral_constant<my_enum,my_enum::test>>);
}
