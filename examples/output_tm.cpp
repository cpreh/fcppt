//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// ![output_tm]
#include <fcppt/string_conv_locale.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/time/gmtime.hpp>
#include <fcppt/time/output_tm.hpp>
#include <fcppt/time/std_time.hpp>

int main()
{
  fcppt::io::cout().imbue(fcppt::string_conv_locale());

  fcppt::time::output_tm(fcppt::io::cout(), fcppt::time::gmtime(fcppt::time::std_time()))
      << FCPPT_TEXT('\n');
}
// ![output_tm]
