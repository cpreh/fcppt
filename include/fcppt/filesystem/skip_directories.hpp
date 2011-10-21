//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_SKIP_DIRECTORIES_HPP_INCLUDED
#define FCPPT_FILESYSTEM_SKIP_DIRECTORIES_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/filesystem/directory_iterator.hpp>


namespace fcppt
{
namespace filesystem
{

FCPPT_SYMBOL
filesystem::directory_iterator const
skip_directories(
	filesystem::directory_iterator
);

}
}

#endif
