//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TIME_OUTPUT_TM_HPP_INCLUDED
#define FCPPT_TIME_OUTPUT_TM_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <iterator>
#include <locale>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt::time
{
/**
\brief Outputs a <code>%std::tm</code> to a stream.

\ingroup fcppttime

Outputs \a tm to \a stream using the <code>std::time_put</code> locale facet,
obtained from the locale of \a stream. Example:
\snippet output_tm.cpp output_tm
*/
template<typename Ch, typename Traits>
void output_tm(std::basic_ostream<Ch, Traits> &_stream, std::tm const &_tm)
{
  typename std::basic_ostream<Ch, Traits>::sentry const cerberos{_stream};

  if (!cerberos)
  {
    return;
  }

  std::use_facet<std::time_put<Ch, std::ostreambuf_iterator<Ch, Traits>>>(_stream.getloc())
      .put(_stream, _stream, _stream.fill(), &_tm, 'c');
}

}

#endif
