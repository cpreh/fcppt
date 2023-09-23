//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/from_std_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/error/strerror.hpp>
#include <fcppt/config/external_begin.hpp>
#include <system_error>
#include <fcppt/config/external_end.hpp>

fcppt::string fcppt::error::strerror(int const _errnum)
{
  return fcppt::from_std_string(std::error_code{_errnum, std::system_category()}.message());
}
