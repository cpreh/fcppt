//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_TYPES_HPP_INCLUDED
#define FCPPT_ITERATOR_TYPES_HPP_INCLUDED


namespace fcppt
{
namespace iterator
{

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
