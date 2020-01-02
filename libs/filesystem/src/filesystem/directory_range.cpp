//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/directory_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::filesystem::directory_range::directory_range(
	std::filesystem::path _path
)
:
	begin_{
		std::move(
			_path
		)
	}
{
}

std::filesystem::directory_iterator
fcppt::filesystem::directory_range::begin() const
{
	return
		begin_;
}

std::filesystem::directory_iterator
fcppt::filesystem::directory_range::end() const
{
	return
		std::filesystem::directory_iterator();
}
