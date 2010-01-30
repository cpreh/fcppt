//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_CREATE_DIRECTORY_FAILED_HPP_INCLUDED
#define FCPPT_FILESYSTEM_CREATE_DIRECTORY_FAILED_HPP_INCLUDED

#include <fcppt/filesystem/exception.hpp>
#include <fcppt/filesystem/create_directory_failed.hpp>
#include <fcppt/filesystem/path.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace filesystem
{

class FCPPT_CLASS_SYMBOL create_directory_failed
:
	public exception
{
public:
	FCPPT_SYMBOL explicit create_directory_failed(
		path const &
	);
};

}
}

#endif
