//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/all_of.hpp>
#include <fcppt/mpl/list/all_of_v.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(
      // NOLINTNEXTLINE(modernize-type-traits)
      fcppt::mpl::list::all_of<fcppt::mpl::list::object<>, fcppt::mpl::lambda<std::is_integral>>::
          value);

  static_assert(
      // NOLINTNEXTLINE(modernize-type-traits)
      fcppt::mpl::list::
          all_of<fcppt::mpl::list::object<int, bool>, fcppt::mpl::lambda<std::is_integral>>::value);

  static_assert(
      // NOLINTNEXTLINE(modernize-type-traits)
      !fcppt::mpl::list::
          all_of<fcppt::mpl::list::object<int, void>, fcppt::mpl::lambda<std::is_integral>>::value);

  static_assert(
      fcppt::mpl::list::all_of_v<fcppt::mpl::list::object<>, fcppt::mpl::lambda<std::is_integral>>);

  static_assert(
      fcppt::mpl::list::
          all_of_v<fcppt::mpl::list::object<int, bool>, fcppt::mpl::lambda<std::is_integral>>);

  static_assert(
      !fcppt::mpl::list::
          all_of_v<fcppt::mpl::list::object<int, void>, fcppt::mpl::lambda<std::is_integral>>);
}
