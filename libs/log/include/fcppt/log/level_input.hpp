//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_INPUT_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_INPUT_HPP_INCLUDED

#include <fcppt/io/istream_fwd.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Reads a level from a stream.

\ingroup fcpptlog
*/
FCPPT_LOG_DETAIL_SYMBOL
fcppt::io::istream &
operator>>(
	fcppt::io::istream &,
	fcppt::log::level &
);

}
}

#endif
