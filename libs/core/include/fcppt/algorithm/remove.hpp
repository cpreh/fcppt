//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_REMOVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_REMOVE_HPP_INCLUDED

#include <fcppt/algorithm/remove_if.hpp>

namespace fcppt
{
namespace algorithm
{
/**
\brief Removes all occurrences of a value from a container

Removes all elements from a \p _container equal to \p _element.

\ingroup fcpptalgorithm

\return <code>true</code> if something has been removed, <code>false</code>
otherwise.
*/
template <typename Container>
inline bool remove(Container &_container, typename Container::const_reference _element)
{
  return fcppt::algorithm::remove_if(
      _container,
      [_element](typename Container::const_reference _ref) { return _element == _ref; });
}

}
}

#endif
