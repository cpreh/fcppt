//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_NUM_SUBPATHS_HPP_INCLUDED
#define FCPPT_FILESYSTEM_NUM_SUBPATHS_HPP_INCLUDED

#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Returns how many sub-paths a path has

\ingroup fcpptfilesystem

Returns how many sub-path \a path has

\param path The path to count the sub-paths of
*/
FCPPT_FILESYSTEM_DETAIL_SYMBOL
std::size_t
num_subpaths(
	boost::filesystem::path const &path
);

}
}

#endif
