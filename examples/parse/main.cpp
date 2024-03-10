//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/copy.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/parse/convert_const.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error.hpp>
#include <fcppt/parse/parse_string_error_output.hpp>
#include <fcppt/parse/operators/alternative.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace
{
// [digit]
enum class digit : std::uint8_t
{
  _0,
  _1,
  _2,
  _3,
  _4,
  _5,
  _6,
  _7,
  _8,
  _9
};
// [digit]

void print(std::vector<digit> const &) {}

// [make_digit]
auto make_digit(char const c, digit const d)
{
  return fcppt::parse::convert_const{fcppt::parse::literal{c}, fcppt::copy(d)};
}
// [make_digit]

}

int main()
{
// [parser_digit]
  auto const p09{
      make_digit('0', digit::_0) | make_digit('1', digit::_1) | make_digit('2', digit::_2) |
      make_digit('3', digit::_3) | make_digit('4', digit::_4) | make_digit('5', digit::_5) |
      make_digit('6', digit::_6) | make_digit('7', digit::_7) | make_digit('8', digit::_8) |
      make_digit('9', digit::_9)};
// [parser_digit]

// [parser_digit_string]
  auto const p09_repeat{*fcppt::make_cref(p09)};
// [parser_digit_string]

// [parser_example]
  fcppt::either::match(
      fcppt::parse::parse_string(p09_repeat, std::string{"12345"}),
      [](fcppt::parse::parse_string_error<char> const &error) { std::cerr << error << '\n'; },
      [](std::vector<digit> const &result) {
        std::cout << "Success\n";
        print(result);
      });
// [parser_example]
}
