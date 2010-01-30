//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/remove.hpp>
#include <boost/filesystem/operations.hpp>

bool
fcppt::filesystem::remove(
	path const &_p)
{
	return 
		boost::filesystem::remove(
			_p);
}
