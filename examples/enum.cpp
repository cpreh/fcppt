//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/enum_to_underlying.hpp>
#include <fcppt/enum/array.hpp>
#include <fcppt/enum/from_string.hpp>
#include <fcppt/enum/make_range.hpp>
#include <fcppt/enum/max_value.hpp>
#include <fcppt/enum/names_array.hpp>
#include <fcppt/enum/names_impl_fwd.hpp>
#include <fcppt/enum/to_string.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>

namespace
{
//! [enum_maximum]
enum class myenum
{
  val1,
  val2,
  fcppt_maximum = val2
};
//! [enum_maximum]

void print_enum(myenum const _value)
{
  std::cout <<
      // Convert to an integer
      fcppt::cast::enum_to_underlying(_value) << '\n';
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wglobal-constructors)
FCPPT_PP_DISABLE_CLANG_WARNING(-Wexit-time-destructors)

// ![enum_names]
namespace
{
// NOLINTNEXTLINE(fuchsia-statically-constructed-objects)
fcppt::enum_::names_array<myenum> const names{// NOLINT(cert-err58-cpp)
                                              fcppt::string{FCPPT_TEXT("val1")},
                                              fcppt::string{FCPPT_TEXT("val2")}};

}

namespace fcppt::enum_
{
template <>
struct names_impl<myenum>
{
  static fcppt::enum_::names_array<myenum> const &get() { return ::names; }
};

}
// ![enum_names]

FCPPT_PP_POP_WARNING

namespace
{
void enum_to_string()
{
  // ![enum_to_string]
  myenum const test{myenum::val2};

  fcppt::string const converted{fcppt::enum_::to_string(test)};
  // ![enum_to_string]
  fcppt::io::cout() << converted << FCPPT_TEXT('\n');
}

void enum_from_string()
{
  // ![enum_from_string]
  // Returns an empty optional
  fcppt::optional::object<myenum> const enum1{
      fcppt::enum_::from_string<myenum>(FCPPT_TEXT("test"))};

  // Returns myenum::val1
  fcppt::optional::object<myenum> const enum2{
      fcppt::enum_::from_string<myenum>(FCPPT_TEXT("val1"))};
  // ![enum_from_string]

  fcppt::io::cout() << enum1.has_value() << FCPPT_TEXT('\n') << enum2.has_value()
                    << FCPPT_TEXT('\n');
}

}

int main()
{
  print();

  iterate();

  enum_array();

  enum_to_string();

  enum_from_string();
}
