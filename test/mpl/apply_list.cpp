//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/apply_list.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(fcppt::mpl::apply_list<fcppt::mpl::lambda<std::is_integral>,fcppt::mpl::list<int>>::value);
  static_assert(fcppt::mpl::apply_list<fcppt::mpl::lambda<std::is_same>,fcppt::mpl::list<int,int>>::value);
}
