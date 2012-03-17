//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_CREATE_DIRECTORY_FAILED_HPP_INCLUDED
#define FCPPT_FILESYSTEM_CREATE_DIRECTORY_FAILED_HPP_INCLUDED

#include <fcppt/filesystem/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Thrown by the functions that try to create directories

\ingroup fcpptfilesystem
*/
class create_directory_failed
:
	public fcppt::filesystem::exception
{
public:
	/**
	\brief Constructs the exception

	Constructs the exception from \a path.

	\param path The path that couldn't be created
	*/
	explicit
	create_directory_failed(
		boost::filesystem::path const &path
	);
};

}
}

#include <fcppt/filesystem/impl/create_directory_failed.hpp>

#endif
