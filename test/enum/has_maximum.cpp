//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/not.hpp>
#include <fcppt/enum/has_maximum.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

namespace
{
enum class enum1 : std::uint8_t
{
  a,
  b
};

enum class enum2 : std::uint8_t
{
 a,
 b,
 fcppt_maximum
};

}
int main()
{
  static_assert(fcppt::not_(fcppt::enum_::has_maximum<enum1>::value));
  static_assert(fcppt::enum_::has_maximum<enum2>::value);
}
