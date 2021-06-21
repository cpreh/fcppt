//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/list/index_of_if.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  using list = fcppt::mpl::list::object<int, float>;

  static_assert(std::is_same_v<
                fcppt::mpl::list::index_of_if<list, fcppt::mpl::lambda<std::is_integral>>,
                fcppt::mpl::size_type<0>>);

  static_assert(std::is_same_v<
                fcppt::mpl::list::index_of_if<list, fcppt::mpl::lambda<std::is_floating_point>>,
                fcppt::mpl::size_type<1>>);
}
