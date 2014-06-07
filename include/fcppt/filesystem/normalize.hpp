//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_NORMALIZE_HPP_INCLUDED
#define FCPPT_FILESYSTEM_NORMALIZE_HPP_INCLUDED

#include <fcppt/filesystem/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Normalizes a path by removing trailing slashes

\ingroup fcpptfilesystem

Returns a copy of \a path with trailing slashes removed.

\param path The path to remove trailing slashes from
*/
FCPPT_FILESYSTEM_SYMBOL
boost::filesystem::path
normalize(
	boost::filesystem::path const &path
);

}
}

#endif
