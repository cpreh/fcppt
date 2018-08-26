//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_TYPES_HPP_INCLUDED
#define FCPPT_ITERATOR_TYPES_HPP_INCLUDED


namespace fcppt
{
namespace iterator
{

/**
\brief The types passed to \link fcppt::iterator::base\endlink.

\ingroup fcpptiterator

\tparam Derived The derived type of \link fcppt::iterator::base\endlink.

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
template<
	typename Derived,
	typename ValueType,
	typename Reference,
	typename DifferenceType,
	typename IteratorCategory
>
struct types
{
	typedef
	Derived
	derived;

	typedef
	ValueType
	value_type;

	typedef
	Reference
	reference;

	typedef
	DifferenceType
	difference_type;

	typedef
	IteratorCategory
	iterator_category;
};

}
}

#endif
