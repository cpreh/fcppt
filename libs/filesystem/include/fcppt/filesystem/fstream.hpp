//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_FILESYSTEM_FSTREAM_HPP_INCLUDED
#define FCPPT_FILESYSTEM_FSTREAM_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <fstream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace filesystem
{
/**
\brief Typedef to <code>basic_fstream</code>, depending on fcppt::char_type.

\ingroup fcpptstring
*/
using fstream = std::basic_fstream<fcppt::char_type>;

}
}

#endif
