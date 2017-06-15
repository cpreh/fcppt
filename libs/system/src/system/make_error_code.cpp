//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/system/make_optional_error_code.hpp>
#include <fcppt/system/optional_error_code.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/system/error_code.hpp>
#include <fcppt/config/external_end.hpp>


fcppt::system::optional_error_code
fcppt::system::make_optional_error_code(
	boost::system::error_code const &_error
)
{
	return
		_error
		?
			fcppt::system::optional_error_code{
				_error
			}
		:
			fcppt::system::optional_error_code{}
		;
}
