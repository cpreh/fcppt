//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/copy.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/options/invalid_name.hpp>
#include <fcppt/options/detail/check_name.hpp>

void fcppt::options::detail::check_name(fcppt::string const &_name)
{
  if(_name.starts_with(FCPPT_TEXT('-')))
  {
    throw fcppt::options::invalid_name{fcppt::copy(_name)};
  }
}
