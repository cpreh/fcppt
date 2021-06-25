//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/list/enum_range.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
enum class my_enum
{
  test1,
  test2,
  fcppt_maximum = test2
};

}

int main()
{
  static_assert(std::is_same_v<
                fcppt::mpl::list::enum_range<my_enum>,
                fcppt::mpl::list::object<
                    std::integral_constant<my_enum, my_enum::test1>,
                    std::integral_constant<my_enum, my_enum::test2>>>);
}
