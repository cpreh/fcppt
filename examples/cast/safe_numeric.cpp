//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/text.hpp>
#include <fcppt/cast/safe_numeric.hpp>
#include <fcppt/io/cout.hpp>

namespace
{
//! [safe_numeric_cast_class]
class my_class
{
public:
  using int_type = unsigned long; // NOLINT(google-runtime-int)
  // The constructor would normally be declared like this:
  /*
  explicit
  my_class(int_type);
  */

  // Use a templated constructor here so no implicit conversions take
  // place when calling the constructor. The implicit conversions will be
  // done by safe_numeric instead, and the unsafe ones will be
  // forbidden.
  template <typename Other>
  explicit my_class(Other const &_other) : inner_(fcppt::cast::safe_numeric<int_type>(_other))
  {
  }

private:
  int_type inner_;
};
//! [safe_numeric_cast_class]

}

int main()
{
  //! [safe_numeric_cast_objects]
  // Ok, because an unsigned int can be converted to an unsigned long
  my_class const test1(1U);

  // Doesn't compile, because the signedness is different, although it
  // would work at runtime. The value could as well be negative.
  // my_class const test2(1);

  // Dito.
  // my_class const test3(-1);

  // Conversions from floats don't work either.
  // my_class const test4(3.f);
  //! [safe_numeric_cast_objects]
}
