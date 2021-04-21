//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/information.hpp>
#include <fcppt/assert/make_message.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/assert/unreachable.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace
{
// ![assert_unreachable]
enum class food
{
  apple,
  banana,
  potato,
  bread
};

// Check if a given kind of food is a fruit
bool is_fruit(food const _value)
{
  // Handle every possible enumerator
  switch (_value)
  {
  case food::apple:
  case food::banana:
    return true;
  case food::potato:
  case food::bread:
    return false;
  }

  // This should never be reached
  FCPPT_ASSERT_UNREACHABLE;
}
// ![assert_unreachable]

}

int main()
try
{
  is_fruit(food::apple);
}
catch (fcppt::exception const &_error)
{
  fcppt::io::cerr() << _error.string() << FCPPT_TEXT('\n');
}
