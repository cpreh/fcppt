//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ITERATOR_TYPES_HPP_INCLUDED
#define FCPPT_ITERATOR_TYPES_HPP_INCLUDED

namespace fcppt::iterator
{
/**
\brief The types passed to #fcppt::iterator::base.

\ingroup fcpptiterator

\tparam Derived The derived type of #fcppt::iterator::base.

\tparam ValueType The value type of the iterator. This must be a type
that users of the iterator can store a dereferenced value in.

\tparam Reference The return value of <code>operator*</code>. If the
iterator is at least a forward iterator, then this must be a (const) reference
to \a ValueType.

\tparam DifferenceType The difference type used for random access iterators.
This is used to move an iterator forwards/backwards and to calculate the
distance between two iterators.

\tparam IteratorCategory The category of the iterator. Must be one of the
<code>std::</code> iterator category classes.
*/
template <
    typename Derived,
    typename ValueType,
    typename Reference,
    typename DifferenceType,
    typename IteratorCategory>
struct types
{
  using derived = Derived;

  using value_type = ValueType;

  using reference = Reference;

  using difference_type = DifferenceType;

  using iterator_category = IteratorCategory;
};

}

#endif
