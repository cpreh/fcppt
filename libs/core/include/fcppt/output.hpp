//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OUTPUT_HPP_INCLUDED
#define FCPPT_OUTPUT_HPP_INCLUDED

#include <fcppt/output_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Outputs an object.

\ingroup fcpptvarious

Calls fcppt::output_impl::execute to output \a _arg.
The default implementation uses <code>operator<< </code>.
*/
template <typename Ch, typename Traits, typename Arg>
inline void output(std::basic_ostream<Ch, Traits> &_stream, Arg const &_arg)
{
  fcppt::output_impl<Arg>::execute(_stream, _arg);
}
}

#endif
