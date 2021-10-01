//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IO_ISTRINGSTREAM_FWD_HPP_INCLUDED
#define FCPPT_IO_ISTRINGSTREAM_FWD_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>

namespace fcppt::io
{
/**
\brief Typedef to either std::istringstream or std::wistringstream, depending on #fcppt::char_type.
\ingroup fcpptstring

See \ref fcpptstring for a motivation for this.
*/
using istringstream = std::basic_istringstream<fcppt::char_type>;

}

#endif
