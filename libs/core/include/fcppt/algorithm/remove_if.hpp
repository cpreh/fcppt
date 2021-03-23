//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_REMOVE_IF_HPP_INCLUDED
#define FCPPT_ALGORITHM_REMOVE_IF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{
/**
\brief Removes all elements from a container matching a predicate.

\ingroup fcpptalgorithm

Removes all elements from \p _container matching \p _predicate.

\tparam Predicate A function callable as <code>bool (Container::value_type)</code>.

\return <code>true</code> if something has been removed, <code>false</code>
otherwise.
*/
template <typename Container, typename Predicate>
bool remove_if(Container &_container, Predicate const &_predicate)
{
  auto const end{
      _container.end() // NOLINT(fuchsia-default-arguments-calls)
  };

  auto const position(std::remove_if(_container.begin(), end, _predicate));

  if (position == end)
  {
    return false;
  }

  _container.erase(
      position, // NOLINT(fuchsia-default-arguments-calls)
      end // NOLINT(fuchsia-default-arguments-calls)
  );

  return true;
}

}
}

#endif
