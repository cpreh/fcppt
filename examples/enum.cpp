//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/enum_to_underlying.hpp>
#include <fcppt/cast/promote_int.hpp>
#include <fcppt/enum/array.hpp>
#include <fcppt/enum/define_max_value.hpp>
#include <fcppt/enum/from_string.hpp>
#include <fcppt/enum/make_invalid.hpp>
#include <fcppt/enum/make_range.hpp>
#include <fcppt/enum/max_value.hpp>
#include <fcppt/enum/to_string.hpp>
#include <fcppt/enum/to_string_impl_fwd.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <string_view>
#include <fcppt/config/external_end.hpp>

namespace
{
//! [enum_def]
enum class myenum : std::uint8_t
{
  val1,
  val2
};
//! [enum_def]
}

//! [enum_maximum]
FCPPT_ENUM_DEFINE_MAX_VALUE(myenum::val2)
//! [enum_maximum]

namespace
{
void print_enum(myenum const _value)
{
  std::cout <<
      // Convert to an integer
      fcppt::cast::promote_int(fcppt::cast::enum_to_underlying(_value)) << '\n';
}

void print() { print_enum(fcppt::enum_::max_value<myenum>::value); }

void iterate()
{
  // ![enum_range]
  // Prints 0, 1
  for (myenum const value : fcppt::enum_::make_range<myenum>())
  {
    print_enum(value);
  }
  // ![enum_range]
}

void enum_array()
{
  // ![enum_array]
  using array = fcppt::enum_::array<myenum, bool>;

  array const val{true, false};

  std::cout << val[myenum::val1] << '\n';
  // ![enum_array]
}

}

// ![enum_names]
namespace fcppt::enum_
{
template <>
struct to_string_impl<myenum>
{
  static std::string_view get(myenum const _value)
  {
    FCPPT_PP_PUSH_WARNING
    FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
    switch (_value)
    {
    case myenum::val1:
      return "val1";
    case myenum::val2:
      return "val2";
    }
    FCPPT_PP_POP_WARNING
    throw fcppt::enum_::make_invalid(_value);
  }
};
}
// ![enum_names]

namespace
{
void enum_to_string()
{
  // ![enum_to_string]
  myenum const test{myenum::val2};

  std::string const converted{fcppt::enum_::to_string(test)};
  // ![enum_to_string]
  std::cout << converted << '\n';
}

void enum_from_string()
{
// ![enum_from_string]
  // Returns an empty optional
  fcppt::optional::object<myenum> const enum1{
      fcppt::enum_::from_string<myenum>("test")};

  // Returns myenum::val1
  fcppt::optional::object<myenum> const enum2{
      fcppt::enum_::from_string<myenum>("val1")};
// ![enum_from_string]

  std::cout << enum1.has_value() << '\n' << enum2.has_value() << '\n';
}

}

int main()
try
{
  print();

  iterate();

  enum_array();

  enum_to_string();

  enum_from_string();
}
catch(std::exception const &_error)
{
  std::cerr << _error.what() << '\n';
  return EXIT_FAILURE;
}
