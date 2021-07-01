//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/list/contains.hpp>
#include <fcppt/mpl/list/transpose.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(std::is_same_v<
                fcppt::mpl::list::transpose<fcppt::mpl::list::object<
                    fcppt::mpl::list::object<>,
                    fcppt::mpl::list::object<>,
                    fcppt::mpl::list::object<>>>,
                fcppt::mpl::list::object<>>);

  static_assert(std::is_same_v<
                fcppt::mpl::list::transpose<fcppt::mpl::list::object<
                    fcppt::mpl::list::object<int, float>,
                    fcppt::mpl::list::object<double, char>>>,
                fcppt::mpl::list::object<
                    fcppt::mpl::list::object<int, double>,
                    fcppt::mpl::list::object<float, char>>>);
}
