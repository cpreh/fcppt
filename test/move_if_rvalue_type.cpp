//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/move_if_rvalue_type.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  using int_unique_ptr = fcppt::unique_ptr<int>;

  static_assert(std::is_same_v<
                fcppt::move_if_rvalue_type<int_unique_ptr, int_unique_ptr &>,
                int_unique_ptr &&>);

  static_assert(std::is_same_v<fcppt::move_if_rvalue_type<int &, float &>, float &>);

  static_assert(std::is_same_v<fcppt::move_if_rvalue_type<int &, int>, int &&>);
}
