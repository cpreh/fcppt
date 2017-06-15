//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_OUTPUT_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_OUTPUT_HPP_INCLUDED

#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Outputs a level to a stream.

\ingroup fcpptlog
*/
FCPPT_LOG_DETAIL_SYMBOL
fcppt::io::ostream &
operator<<(
	fcppt::io::ostream &,
	fcppt::log::level
);

}
}

#endif
