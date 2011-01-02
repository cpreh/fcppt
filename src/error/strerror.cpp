//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/error/strerror.hpp>
#include <fcppt/from_std_string.hpp>
#include <cstring>

fcppt::string const
fcppt::error::strerror(
	int const errnum
)
{
	return from_std_string(
		std::strerror(
			errnum
		)
	);
}
