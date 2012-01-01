//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/readlink.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/operations.hpp>
#include <fcppt/config/external_end.hpp>

fcppt::filesystem::path const
fcppt::filesystem::readlink(
	fcppt::filesystem::path const &_link
)
{
	return
		boost::filesystem::read_symlink(
			_link
		);
}
