//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// ![output_tm]
#include <fcppt/string_conv_locale.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/time/gmtime.hpp>
#include <fcppt/time/output_tm.hpp>
#include <fcppt/time/std_time.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <iostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  std::cout.imbue(fcppt::string_conv_locale());

  fcppt::optional::maybe_void(
      fcppt::time::std_time(),
      [](std::time_t const _time)
      {
        fcppt::optional::maybe_void(
            fcppt::time::gmtime(_time),
            [](std::tm const &_tm)
            {
              fcppt::time::output_tm(std::cout, _tm);
              std::cout << '\n';
            });
      });
}
// ![output_tm]
