//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/to_signed.hpp>
#include <fcppt/filesystem/num_subpaths.hpp>
#include <fcppt/filesystem/strip_prefix.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


boost::filesystem::path
fcppt::filesystem::strip_prefix(
	boost::filesystem::path const &_prefix,
	boost::filesystem::path const &_path
)
{
	boost::filesystem::path result;

	std::for_each(
		std::next(
			_path.begin(),
			fcppt::cast::to_signed(
				fcppt::filesystem::num_subpaths(
					_prefix
				)
			)
		),
		_path.end(),
		[
			&result
		](
			boost::filesystem::path const &_entry
		)
		{
			result /=
				_entry;
		}
	);

	return
		result;
}
