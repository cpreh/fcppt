//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/major_version.hpp>
#include <fcppt/micro_version.hpp>
#include <fcppt/minor_version.hpp>
#include <fcppt/output_to_std_string.hpp>
#include <fcppt/version_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

std::string fcppt::version_string()
{
  return fcppt::output_to_std_string(fcppt::major_version::value) + '.' +
         fcppt::output_to_std_string(fcppt::minor_version::value) + '.' +
         fcppt::output_to_std_string(fcppt::micro_version::value);
}
