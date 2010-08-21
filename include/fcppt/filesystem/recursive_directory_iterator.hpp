//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_RECURSIVE_DIRECTORY_ITERATOR_HPP_INCLUDED
#define FCPPT_FILESYSTEM_RECURSIVE_DIRECTORY_ITERATOR_HPP_INCLUDED

#include <fcppt/filesystem/config.hpp>
#ifndef FCPPT_USE_FILESYSTEM_V3
#include <fcppt/filesystem/path.hpp>
#endif
#include <boost/filesystem/convenience.hpp>

namespace fcppt
{
namespace filesystem
{

#ifndef FCPPT_USE_FILESYSTEM_V3
typedef boost::filesystem::basic_recursive_directory_iterator<
	path
> recursive_directory_iterator;
#else
typedef boost::filesystem::recursive_directory_iterator recursive_directory_iterator;
#endif

}
}

#endif
