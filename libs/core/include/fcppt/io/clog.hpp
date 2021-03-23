//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IO_CLOG_HPP_INCLUDED
#define FCPPT_IO_CLOG_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/io/ostream.hpp>

namespace fcppt
{
namespace io
{
/**
\brief Returns either std::clog or std::wclog, depending on #fcppt::char_type.
\ingroup fcpptstring

See \ref fcpptstring for a motivation for this.
*/
FCPPT_DETAIL_SYMBOL
fcppt::io::ostream &clog();

}
}

#endif
