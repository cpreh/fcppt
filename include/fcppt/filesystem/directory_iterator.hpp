//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_DIRECTORY_ITERATOR_HPP_INCLUDED
#define FCPPT_FILESYSTEM_DIRECTORY_ITERATOR_HPP_INCLUDED

#include <fcppt/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

namespace fcppt
{
namespace filesystem
{

typedef boost::filesystem::basic_directory_iterator<
	path
> directory_iterator;

}
}

#endif
