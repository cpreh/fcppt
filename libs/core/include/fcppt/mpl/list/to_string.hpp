//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_TO_STRING_HPP_INCLUDED
#define FCPPT_MPL_LIST_TO_STRING_HPP_INCLUDED

#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/list/print.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sstream>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
/**
\brief Converts a list to a string.

\ingroup fcpptmpl

\see fcppt::mpl::list::print
*/
template <fcppt::mpl::list::object_concept Sequence>
std::string to_string()
{
  // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
  std::ostringstream stream{};

  fcppt::mpl::list::print<Sequence>(stream);

  return stream.str();
}
}

#endif
