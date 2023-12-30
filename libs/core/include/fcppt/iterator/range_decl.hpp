//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ITERATOR_RANGE_DECL_HPP_INCLUDED
#define FCPPT_ITERATOR_RANGE_DECL_HPP_INCLUDED

#include <fcppt/iterator/range_fwd.hpp> // IWYU pragma: keep

namespace fcppt::iterator
{
/**
\brief A range formed from two iterators.

\ingroup fcpptiterator

\tparam Iterator Must be an iterator.
*/
template <typename Iterator>
class range
{
public:
  using iterator = Iterator;

  using const_iterator = Iterator;

  range(Iterator begin, Iterator end);

  [[nodiscard]] Iterator begin() const;

  [[nodiscard]] Iterator end() const;

private:
  Iterator begin_;

  Iterator end_;
};

}

#endif
