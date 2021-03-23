//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/type_traits/is_value.hpp>

int main()
{
  class test_class
  {
  };

  enum test_enum
  {
  };

  static_assert(fcppt::type_traits::is_value<int>::value);

  static_assert(fcppt::type_traits::is_value<test_class>::value);

  static_assert(fcppt::type_traits::is_value<test_enum>::value);

  static_assert(fcppt::type_traits::is_value<int *>::value);

  static_assert(fcppt::type_traits::is_value<int const *>::value);

  static_assert(!fcppt::type_traits::is_value<int const>::value);

  static_assert(!fcppt::type_traits::is_value<int volatile>::value);

  static_assert(!fcppt::type_traits::is_value<int &>::value);

  static_assert(!fcppt::type_traits::is_value<int &&>::value);

  static_assert(
      !fcppt::type_traits::is_value<
          int[1] // NOLINT(hicpp-avoid-c-arrays,modernize-avoid-c-arrays,cppcoreguidelines-avoid-c-arrays)
          >::value);

  static_assert(!fcppt::type_traits::is_value<void>::value);

  static_assert(!fcppt::type_traits::is_value<void()>::value);
}
