//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/apply.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(
      fcppt::mpl::list::apply<fcppt::mpl::lambda<std::is_integral>, fcppt::mpl::list::object<int>>::
          value);
  static_assert(
      fcppt::mpl::list::
          apply<fcppt::mpl::lambda<std::is_same>, fcppt::mpl::list::object<int, int>>::value);
}
