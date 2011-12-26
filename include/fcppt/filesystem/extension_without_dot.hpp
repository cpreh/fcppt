//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_EXTENSION_WITHOUT_DOT_HPP_INCLUDED
#define FCPPT_FILESYSTEM_EXTENSION_WITHOUT_DOT_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/filesystem/path.hpp>
#include <fcppt/filesystem/symbol.hpp>


namespace fcppt
{
namespace filesystem
{

/// Returns the file's extension, if any, without the dot
/**
 * @return If a file has the form a.b, b will be returned.
 *         Otherwise the empty string will be returned.
*/
FCPPT_FILESYSTEM_SYMBOL
fcppt::string const
extension_without_dot(
	filesystem::path const &
);

}
}

#endif
