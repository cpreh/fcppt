//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_RECURSIVE_DIRECTORY_RANGE_HPP_INCLUDED
#define FCPPT_FILESYSTEM_RECURSIVE_DIRECTORY_RANGE_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/filesystem/recursive_directory_range_fwd.hpp>
#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <system_error>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief A range for recursive directory iterators.

\ingroup fcpptfilesystem
*/
class recursive_directory_range
{
public:
	FCPPT_FILESYSTEM_DETAIL_SYMBOL
	recursive_directory_range(
		std::filesystem::path const &,
		std::filesystem::directory_options,
		fcppt::reference<
			std::error_code
		>
	);

	FCPPT_FILESYSTEM_DETAIL_SYMBOL
	std::filesystem::recursive_directory_iterator
	begin() const;

	FCPPT_FILESYSTEM_DETAIL_SYMBOL
	std::filesystem::recursive_directory_iterator
	end() const;
private:
	std::filesystem::recursive_directory_iterator begin_;
};

}
}

#endif
