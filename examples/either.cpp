//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/either/apply.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/error.hpp>
#include <fcppt/either/error_from_optional.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/to_exception.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <iostream>
#include <istream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace
{
bool error() { return false; }

// [either_motivation_exception]
int example_function()
{
  // some code
  // ...
  if (error())
  {
    throw std::runtime_error{"something went wrong"};
  }

  return 1;
}
// [either_motivation_exception]

// [either_motivation_either]
using int_or_exception = fcppt::either::object<std::runtime_error, int>;

int_or_exception example_function2()
{
  // some code
  // ...
  if (error())
  {
    return int_or_exception{std::runtime_error{"something went wrong"}};
  }

  return int_or_exception{1};
}
// [either_motivation_either]

// [either_motivation_exception_call]
void caller()
{
  try
  {
    int const result{example_function()};

    std::cout << "result is " << result << '\n';
  }
  catch (std::runtime_error const &)
  {
    // do something else
  }
}
// [either_motivation_exception_call]

// [either_motivation_either_call]
void caller2()
{
  fcppt::either::match(
      example_function2(),
      [](std::runtime_error const &) {
        // do something else
      },
      [](int const _result) { std::cout << "result is " << _result << '\n'; });
}
// [either_motivation_either_call]

// [either_map]
fcppt::either::object<std::runtime_error, int> get_int();

fcppt::either::object<std::runtime_error, std::string> get_string()
{
  return fcppt::either::map(get_int(), [](int const _value) { return std::to_string(_value); });
}
// [either_map]
fcppt::either::object<std::runtime_error, int> get_int()
{
  return fcppt::either::object<std::runtime_error, int>{0};
}

// [either_apply]
fcppt::either::object<std::runtime_error, std::string> get_two_strings()
{
  return fcppt::either::apply(
      [](int const _value1, int const _value2) {
        return std::to_string(_value1) + " " + std::to_string(_value2);
      },
      get_int(),
      get_int());
}
// [either_apply]

//! [either_read_raw]
using int_string_pair = std::pair<int, std::string>;

int_string_pair read_stream_raw(std::istream &_stream)
{
  int result_int{0};

  if (!(_stream >> result_int))
  {
    throw std::runtime_error{"error"};
  }

  std::string result_string{};

  if (!(_stream >> result_string))
  {
    throw std::runtime_error{"error"};
  }

  return int_string_pair{result_int, result_string};
}
//! [either_read_raw]

//! [either_read]
template <typename Type>
fcppt::either::object<std::runtime_error, Type> read(std::istream &_stream)
{
  Type result{};

  using return_type = fcppt::either::object<std::runtime_error, Type>;

  return _stream >> result ? return_type{result} : return_type{std::runtime_error{"error"}};
}
//! [either_read]

//! [either_read_bind]
fcppt::either::object<std::runtime_error, int_string_pair> read_stream_either(std::istream &_stream)
{
  return fcppt::either::bind(read<int>(_stream), [&_stream](int const _int_value) {
    return fcppt::either::map(
        read<std::string>(_stream), [_int_value](std::string const &_string_value) {
          return std::make_pair(_int_value, _string_value);
        });
  });
}
//! [either_read_bind]

//! [either_to_exception]
int_string_pair either_to_exception(std::istream &_stream)
{
  return fcppt::either::to_exception(
      read_stream_either(_stream), [](std::runtime_error const &_error) { return _error; });
}
//! [either_to_exception]

int do_something() { return 1; }

enum class error_code
{
  failure1
};

//! [either_error]
auto either_error(fcppt::optional::object<error_code> const _error)
{
  fcppt::either::error<error_code> const either_error{fcppt::either::error_from_optional(_error)};

  return fcppt::either::map(either_error, [](fcppt::either::no_error) {
    // Do something in case of no error.
    return do_something();
  });
}
//! [either_error]

}

int main()
try
{
  {
    std::istringstream stream("42 test");

    std::cout << read_stream_raw(stream).first << '\n';
  }

  {
    std::istringstream stream("42 test");

    std::cout << read_stream_either(stream).has_success() << '\n';
  }

  {
    std::istringstream stream("42 test");

    either_to_exception(stream);
  }

  either_error(fcppt::optional::make(error_code::failure1));

  caller();

  caller2();

  get_string();

  get_two_strings();
}
catch (std::exception const &)
{
}
