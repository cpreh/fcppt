//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <fcppt/config/external_end.hpp>

namespace
{
void something() {}

}

int main()
try
{
  {
    //![text_literal]
    fcppt::string const s{FCPPT_TEXT("foo")};
    //![text_literal]

    fcppt::io::cout() << s << FCPPT_TEXT('\n');
  }

  //[exception]
  try
  {
    something();
  }
  catch (fcppt::exception const &_error)
  {
    fcppt::io::cerr() << _error.string() << FCPPT_TEXT('\n');
  }
  //[exception]
}
catch(std::exception const &_error)
{
  std::cerr << _error.what() << '\n';
  return EXIT_FAILURE;
}
