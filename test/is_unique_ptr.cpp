//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/c_deleter_fwd.hpp>
#include <fcppt/is_unique_ptr.hpp>
#include <fcppt/unique_ptr_fwd.hpp>

int main()
{
  static_assert(fcppt::is_unique_ptr<fcppt::unique_ptr<int>>::value);

  static_assert(fcppt::is_unique_ptr<fcppt::unique_ptr<int, fcppt::c_deleter>>::value);

  static_assert(!fcppt::is_unique_ptr<int>::value);
}
