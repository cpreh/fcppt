//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_REVERSE_HPP_INCLUDED
#define FCPPT_ALGORITHM_REVERSE_HPP_INCLUDED

#include <fcppt/algorithm/detail/reverse.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{
/**
\brief Reverses a container

\ingroup fcpptalgorithm

\tparam Container Must be a bidirectional container
*/
template <typename Container>
inline std::remove_cvref_t<Container> reverse(Container &&_container)
{
  return fcppt::algorithm::detail::reverse(std::forward<Container>(_container));
}

}
}

#endif
