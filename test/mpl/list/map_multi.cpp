//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/map_multi.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(std::is_same_v<
                fcppt::mpl::list::map_multi<
                    fcppt::mpl::lambda<std::common_type_t>,
                    fcppt::mpl::list::object<int, float>,
                    fcppt::mpl::list::object<char, double>>,
                fcppt::mpl::list::object<int, double>>);
}
