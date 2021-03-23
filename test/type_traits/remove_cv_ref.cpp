//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(
      std::is_same<fcppt::type_traits::remove_cv_ref_t<int const &>, int>::value,
      "remove_cv_ref of int const & should be int");

  static_assert(
      std::is_same<fcppt::type_traits::remove_cv_ref_t<int &>, int>::value,
      "remove_cv_ref of int & should be int");
}
