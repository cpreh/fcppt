//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/container/tree/make_to_root.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/container/tree/to_root.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  // TODO(philipp): Make a proper testcase

  using i_tree = fcppt::container::tree::object<int>;

  i_tree tree{1};

  static_assert(std::is_same_v<
                decltype(fcppt::container::tree::make_to_root(tree)),
                fcppt::container::tree::to_root<i_tree>>);

  i_tree const c_tree{1};

  static_assert(std::is_same_v<
                decltype(fcppt::container::tree::make_to_root(c_tree)),
                fcppt::container::tree::to_root<i_tree const>>);
}
