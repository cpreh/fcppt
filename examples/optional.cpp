//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/reference.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace
{
//! [optional_example_bad]
void optional_example_bad(fcppt::optional::object<unsigned> const _opt)
{
  if (_opt.has_value())
  {
    std::cout << _opt.get_unsafe() << '\n';
  }
  else
  {
    std::cout << "No value\n";
  }
}
//! [optional_example_bad]

//! [optional_example_good]
void optional_example_good(fcppt::optional::object<unsigned> const _opt)
{
  fcppt::optional::maybe(
      _opt,
      [] { std::cout << "No value\n"; },
      [](unsigned const _val) { std::cout << _val << '\n'; });
}
//! [optional_example_good]

void optional_copy()
{
  //! [optional_copy]
  using optional_uint = fcppt::optional::object<unsigned>;

  unsigned int1{5U};

  // opt takes a copy of int1
  optional_uint opt{int1};

  int1 = 10U;

  // The value of opt will still be 5u
  std::cout << (opt != optional_uint{int1}) << '\n';
  //! [optional_copy]
}

void optional_bind()
{
  //! [optional_bind]
  using optional_uint = fcppt::optional::object<unsigned>;

  using optional_string = fcppt::optional::object<std::string>;

  optional_string const value{fcppt::optional::bind(optional_uint{1U}, [](unsigned const _val) {
    return optional_string(std::to_string(_val));
  })};

  std::cout << (value == optional_string{"1"}) << '\n';
  //! [optional_bind]

  //! [optional_map]
  optional_string const value2{fcppt::optional::map(
      optional_uint{1U}, [](unsigned const _val) { return std::to_string(_val); })};

  std::cout << (value == optional_string{"1"}) << '\n';
  //! [optional_map]
}

void from_optional()
{
  //! [from_optional]
  using optional_uint = fcppt::optional::object<unsigned>;

  unsigned const value{fcppt::optional::from(optional_uint(), [] { return 1U; })};

  std::cout << (value == 1U) << '\n';
  //! [from_optional]
}

//! [optional_reference]
using optional_int = fcppt::optional::object<int>;

void set_ref(optional_int _opt_ref)
{
  fcppt::optional::maybe_void(_opt_ref, [](int &_ref) { _ref = 1; });
}
//! [optional_reference]

//! [optional_reference_2]
using optional_int_ref = fcppt::optional::reference<int>;

void set_ref2(optional_int_ref const _opt_ref)
{
  fcppt::optional::maybe_void(_opt_ref, [](fcppt::reference<int> const _ref) { _ref.get() = 1; });
}
//! [optional_reference_2]

}

int main()
{
  optional_example_bad(fcppt::optional::object<unsigned>(0));

  optional_example_good(fcppt::optional::object<unsigned>(0));

  optional_copy();

  optional_bind();

  from_optional();

  set_ref(optional_int{});

  set_ref2(optional_int_ref{});
}
