//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_OUTPUT_TM_HPP_INCLUDED
#define FCPPT_TIME_OUTPUT_TM_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace time
{

/**
\brief Outputs an <code>%std::tm</code> to a stream

\ingroup fcppttime

Outputs \a tm to \a stream using the <code>std::time_put</code> locale facet,
obtained from the locale of \a stream. Example:
\snippet output_tm.cpp output_tm

\param stream The stream to output to

\param tm The time struct to output

\return \a stream
*/
FCPPT_DETAIL_SYMBOL
fcppt::io::ostream &
output_tm(
	fcppt::io::ostream &stream,
	std::tm const &tm
);

}
}

#endif
