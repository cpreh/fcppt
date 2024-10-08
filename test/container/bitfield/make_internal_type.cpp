//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/container/bitfield/detail/make_internal_type.hpp>
#include <fcppt/enum/define_max_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
enum class enum1 : std::uint8_t
{
  value = 7
};

enum class enum2 : std::uint8_t
{
  value = 9
};

enum class enum3 : std::uint8_t
{
  value = 100
};
}
FCPPT_ENUM_DEFINE_MAX_VALUE(enum1::value)
FCPPT_ENUM_DEFINE_MAX_VALUE(enum2::value)
FCPPT_ENUM_DEFINE_MAX_VALUE(enum3::value)

namespace
{
static_assert(std::is_same_v<
              fcppt::container::bitfield::detail::make_internal_type<enum1>,
              std::uint_least8_t>);
static_assert(std::is_same_v<
              fcppt::container::bitfield::detail::make_internal_type<enum2>,
              std::uint_least16_t>);
static_assert(std::is_same_v<
              fcppt::container::bitfield::detail::make_internal_type<enum3>,
              std::uint_least64_t>);
}

int main()
{
}
