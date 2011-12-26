//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_NEXT_FILE_HPP_INCLUDED
#define FCPPT_FILESYSTEM_NEXT_FILE_HPP_INCLUDED

#include <fcppt/filesystem/directory_iterator.hpp>
#include <fcppt/filesystem/symbol.hpp>


namespace fcppt
{
namespace filesystem
{

FCPPT_FILESYSTEM_SYMBOL
filesystem::directory_iterator const
next_file(
	filesystem::directory_iterator
);

}
}

#endif
