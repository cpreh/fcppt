//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_FILE_SIZE_HPP_INCLUDED
#define FCPPT_FILESYSTEM_FILE_SIZE_HPP_INCLUDED

#include <fcppt/filesystem/path.hpp>
#include <fcppt/filesystem/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

FCPPT_FILESYSTEM_SYMBOL
boost::uintmax_t
file_size(
	fcppt::filesystem::path const &
);

}
}

#endif
