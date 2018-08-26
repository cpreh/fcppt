//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/from_std_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/system/error_code_to_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/system/error_code.hpp>
#include <fcppt/config/external_end.hpp>


fcppt::string
fcppt::system::error_code_to_string(
	boost::system::error_code const &_error_code
)
{
	return
		fcppt::from_std_string(
			_error_code.message()
		);
}
