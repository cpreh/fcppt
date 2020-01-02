//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_FILE_SIZE_HPP_INCLUDED
#define FCPPT_FILESYSTEM_FILE_SIZE_HPP_INCLUDED

#include <fcppt/filesystem/optional_size.hpp>
#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Returns the size of a file.

\ingroup fcpptfilesystem

Returns the size of \a path if it exists and its size can be obtained,
otherwise returns the empty optional.
*/
FCPPT_FILESYSTEM_DETAIL_SYMBOL
fcppt::filesystem::optional_size
file_size(
	std::filesystem::path const &path
);

}
}

#endif
