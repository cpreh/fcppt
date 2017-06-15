//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/error/strerrno.hpp>
#include <fcppt/error/strerror.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cerrno>
#include <fcppt/config/external_end.hpp>


fcppt::string
fcppt::error::strerrno()
{
	return
		fcppt::error::strerror(
			errno
		);
}
