//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/filesystem/num_subpaths.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <cstddef>
#include <iterator>
#include <fcppt/config/external_end.hpp>


std::size_t
fcppt::filesystem::num_subpaths(
	boost::filesystem::path const &_path
)
{
	return
		fcppt::cast::to_unsigned(
			std::distance(
				_path.begin(),
				_path.end()
			)
		);
}
