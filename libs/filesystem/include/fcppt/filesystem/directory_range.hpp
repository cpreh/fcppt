//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_DIRECTORY_RANGE_HPP_INCLUDED
#define FCPPT_FILESYSTEM_DIRECTORY_RANGE_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/filesystem/directory_range_fwd.hpp>
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
\brief A range for directory iterators.

\ingroup fcpptfilesystem
*/
class directory_range
{
public:
	FCPPT_FILESYSTEM_DETAIL_SYMBOL
	directory_range(
		std::filesystem::path const &,
		std::filesystem::directory_options,
		fcppt::reference<
			std::error_code
		>
	);

	[[nodiscard]]
	FCPPT_FILESYSTEM_DETAIL_SYMBOL
	std::filesystem::directory_iterator
	begin() const;

	[[nodiscard]]
	FCPPT_FILESYSTEM_DETAIL_SYMBOL
	std::filesystem::directory_iterator
	end() const;
private:
	std::filesystem::directory_iterator begin_;
};

}
}

#endif
