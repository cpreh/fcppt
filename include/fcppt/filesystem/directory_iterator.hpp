//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_DIRECTORY_ITERATOR_HPP_INCLUDED
#define FCPPT_FILESYSTEM_DIRECTORY_ITERATOR_HPP_INCLUDED

#include <fcppt/filesystem/config.hpp>
#ifndef FCPPT_USE_FILESYSTEM_V3
#include <fcppt/filesystem/path.hpp>
#endif
#include <boost/filesystem/operations.hpp>

namespace fcppt
{
namespace filesystem
{

#ifndef FCPPT_USE_FILESYSTEM_V3
typedef boost::filesystem::basic_directory_iterator<
	filesystem::path
> directory_iterator;
#else
typedef boost::filesystem::directory_iterator directory_iterator;
#endif

}
}

#endif
