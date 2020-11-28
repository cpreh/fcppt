//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// ![string_conversion]
#include <fcppt/from_std_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/to_std_wstring.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <string>
#include <fcppt/config/external_end.hpp>

int main()
{
  fcppt::string const string(FCPPT_TEXT("test"));

  fcppt::optional::maybe(
      fcppt::to_std_string(string),
      [&string] {
        fcppt::io::cerr() << FCPPT_TEXT("Failed to convert ") << string << FCPPT_TEXT('\n');
      },
      [](std::string const &converted) {
        std::cout << converted << '\n';

        fcppt::io::cout() << fcppt::from_std_string(converted) << FCPPT_TEXT('\n');
      });

  std::wcout << fcppt::to_std_wstring(string) << L'\n';
}
// ![string_conversion]
