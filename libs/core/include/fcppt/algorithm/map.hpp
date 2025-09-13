//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_HPP_INCLUDED

#include <fcppt/algorithm/map_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
/**
\brief Transforms a range to another container by applying a function to every
element.

\ingroup fcpptalgorithm

For every element \em e in \a _source, <code>_function(e)</code> is inserted
into the result container.

\note As an optimization the result container has its capacity set to the
source range's size at the start, if possible. For this to work, the result
container needs a <code>reserve</code> function, and the source range needs a
<code>size</code> function or must be a random-access range.

The actual implementation of the algorithm is provided by #fcppt::algorithm::map_impl which by
default uses #fcppt::algorithm::loop.

\tparam Function Let <code>T_1,...,T_n</code> be the types of \a SourceRange and <code>U_1,...,U_n</code> the types of \a TargetContainer.
Then the function must be callable as <code>U_i(T_i)</code> for every <code>1 <= i <= n</code>.
*/
template <typename TargetContainer, typename SourceRange, typename Function>
TargetContainer map(SourceRange &&_source, Function const &_function)
{
  return fcppt::algorithm::map_impl<std::remove_cvref_t<SourceRange>, TargetContainer>::execute(
      std::forward<SourceRange>(_source), _function);
}

}

#endif
