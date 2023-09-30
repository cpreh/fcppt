//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_MAP_OPTIONAL_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_OPTIONAL_HPP_INCLUDED

#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
/**
\brief Transforms a range to another container by applying a function to
every element, only inserting the results that are not empty optionals.

\ingroup fcpptalgorithm

For every element \em e in \a _source, <code>_function(e)</code> is called. If
the result is not an empty optional, it is inserted into the result container.

\tparam Function A function callable as
<code>fcppt::optional::object<TargetContainer::value_type>
(Source::value_type)</code>.

TODO(philipp): concepts
*/
template <typename TargetContainer, typename Source, typename Function>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
TargetContainer map_optional(Source &&_source, Function const &_function)
{
  TargetContainer result{};

  for (auto &&element : _source)
  {
    fcppt::optional::maybe_void(
        _function(element),
        [&result](auto &&_inner)
        { result.insert(result.end(), std::forward<decltype(_inner)>(_inner)); });
  }

  return result;
}

}

#endif
