//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ITERATOR_MAKE_RANGE_HPP_INCLUDED
#define FCPPT_ITERATOR_MAKE_RANGE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/iterator/range_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::iterator
{
/**
\brief Makes an iterator range.

\ingroup fcpptiterator
*/
template <typename Iterator1, typename Iterator2>
inline fcppt::iterator::range<std::remove_cvref_t<Iterator1>>
make_range(Iterator1 &&_begin, Iterator2 &&_end) // NOLINT(cppcoreguidelines-missing-std-forward)
  requires(std::is_same_v<std::remove_cvref_t<Iterator1>, std::remove_cvref_t<Iterator2>>)
{
  return fcppt::iterator::range<std::remove_cvref_t<Iterator1>>(
      fcppt::move_if_rvalue<Iterator1>(_begin), fcppt::move_if_rvalue<Iterator2>(_end));
}
}

#endif
