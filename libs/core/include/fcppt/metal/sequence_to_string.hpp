//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_SEQUENCE_TO_STRING_HPP_INCLUDED
#define FCPPT_METAL_SEQUENCE_TO_STRING_HPP_INCLUDED

#include <fcppt/metal/print.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sstream>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace metal
{
/**
\brief Converts a sequence to a string.

\ingroup fcpptmetal

\tparam Sequence Must be a metal sequence.
*/
template <typename Sequence>
std::string sequence_to_string()
{
  // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
  std::ostringstream stream{};

  fcppt::metal::print<Sequence>(stream);

  return stream.str();
}

}
}

#endif
