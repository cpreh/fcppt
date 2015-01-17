//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_STEM_HPP_INCLUDED
#define FCPPT_FILESYSTEM_STEM_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Returns the stem of a path as a string

\ingroup fcpptfilesystem

Returns the stem of \a path as a string. The stem is the filename excluding the
extension.

\param path The path to return the stem from

\return A string with the stem of the path, or an empty string if the path has
no filename
*/
FCPPT_FILESYSTEM_DETAIL_SYMBOL
fcppt::string
stem(
	boost::filesystem::path const &path
);

}
}

#endif
