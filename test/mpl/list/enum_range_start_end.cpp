//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/list/enum_range_start_end.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
enum class my_enum : std::uint8_t
{
  test1,
  test2,
  test3,
  test4,
  fcppt_maximum = test4
};

}

int main()
{
  static_assert(std::is_same_v<
                fcppt::mpl::list::enum_range_start_end<
                    std::integral_constant<my_enum, my_enum::test2>,
                    std::integral_constant<my_enum, my_enum::test3>>,
                fcppt::mpl::list::object<
                    std::integral_constant<my_enum, my_enum::test2>,
                    std::integral_constant<my_enum, my_enum::test3>>>);
}
