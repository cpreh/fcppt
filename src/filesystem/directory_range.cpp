//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/directory_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::filesystem::directory_range::directory_range(
	boost::filesystem::path _path
)
:
	begin_{
		std::move(
			_path
		)
	}
{
}

boost::filesystem::directory_iterator
fcppt::filesystem::directory_range::begin() const
{
	return
		begin_;
}

boost::filesystem::directory_iterator
fcppt::filesystem::directory_range::end() const
{
	return
		boost::filesystem::directory_iterator();
}

