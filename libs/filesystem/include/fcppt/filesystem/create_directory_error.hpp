//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_CREATE_DIRECTORY_ERROR_HPP_INCLUDED
#define FCPPT_FILESYSTEM_CREATE_DIRECTORY_ERROR_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/system/error_code.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Returns an error string for a failed create directory operation.

\ingroup fcpptfilesystem
*/
FCPPT_FILESYSTEM_DETAIL_SYMBOL
fcppt::string
create_directory_error(
	boost::filesystem::path const &path,
	boost::system::error_code error
);

}
}

#endif
