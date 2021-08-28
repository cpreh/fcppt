//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OUTPUT_HPP_INCLUDED
#define FCPPT_OUTPUT_HPP_INCLUDED

#include <fcppt/make_cref.hpp>
#include <fcppt/detail/output.hpp>

namespace fcppt
{
/**
\brief Outputs an object.

\ingroup fcpptvarious

Calls fcppt::output_impl::execute to output \a _arg.
The default implementation uses <code>operator<< </code>.
*/
template <typename Arg>
inline fcppt::detail::output<Arg> output(Arg const &_arg)
{
  return fcppt::detail::output<Arg>{fcppt::make_cref(_arg)};
}
}

#endif
