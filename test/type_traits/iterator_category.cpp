//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/type_traits/is_iterator_of_category.hpp>
#include <fcppt/type_traits/is_iterator_of_category_v.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <list>
#include <fcppt/config/external_end.hpp>

int main()
{
  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::type_traits::is_iterator_of_category<int *, std::input_iterator_tag>::value);

  static_assert(
      // NOLINTNEXTLINE(modernize-type-traits)
      fcppt::type_traits::is_iterator_of_category<int *, std::random_access_iterator_tag>::value);

  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(!fcppt::type_traits::is_iterator_of_category<
                std::list<int>::const_iterator,
                std::random_access_iterator_tag>::value);

  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::type_traits::is_iterator_of_category<
                std::list<int>::const_iterator,
                std::bidirectional_iterator_tag>::value);

  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::type_traits::is_iterator_of_category<
                std::list<int>::const_iterator,
                std::forward_iterator_tag>::value);

  static_assert(
      // NOLINTNEXTLINE(modernize-type-traits)
      fcppt::type_traits::
          is_iterator_of_category<std::ostream_iterator<int>, std::output_iterator_tag>::value);

  static_assert(fcppt::type_traits::is_iterator_of_category_v<int *, std::input_iterator_tag>);
}
