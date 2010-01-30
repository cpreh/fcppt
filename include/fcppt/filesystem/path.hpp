//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_PATH_HPP_INCLUDED
#define FCPPT_FILESYSTEM_PATH_HPP_INCLUDED

#include <fcppt/filesystem/detail/path_traits.hpp>
#include <fcppt/string.hpp>
#include <boost/filesystem/path.hpp>

namespace fcppt
{
namespace filesystem
{

typedef boost::filesystem::basic_path<
	string,
	detail::path_traits
> path;

}
}

#endif
