//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/type_traits/is_base_of.hpp>

namespace
{
struct base
{
};

struct derived : base
{
};

struct test
{
};

}

int main()
{
  static_assert(fcppt::type_traits::is_base_of<base, derived>::value);

  static_assert(!fcppt::type_traits::is_base_of<test, derived>::value);
}
