//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_APPLY_HPP_INCLUDED
#define FCPPT_OPTIONS_APPLY_HPP_INCLUDED

#include <fcppt/options/detail/apply.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::options
{
/**
\brief Combines two or more parsers.

\ingroup fcpptoptions

Combines two or more parsers into a single one that parses everything the
individual parsers do. Because the resulting parser produces a record that
contains <em>all</em> labels of the individual parsers, the label sets of
the individual parsers must be pairwise disjoint.
*/
template <typename... Parsers>
inline auto apply(Parsers &&..._parsers)
requires(sizeof...(Parsers) >= 2U)
{
  return fcppt::options::detail::apply(std::forward<Parsers>(_parsers)...);
}

}

#endif
