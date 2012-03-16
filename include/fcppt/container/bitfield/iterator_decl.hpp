//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/container/bitfield/difference_type.hpp>
#include <fcppt/container/bitfield/iterator_fwd.hpp>
#include <fcppt/container/bitfield/value_type.hpp>
#include <fcppt/container/bitfield/detail/iterator_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

/**
\brief The (random-access) iterator type used by
fcppt::container::bitfield::basic

This class provides an iterator over a bitfield, see also
fcppt::container::bitfield::basic::iterator and
fcppt::container::bitfield::const_iterator.

\tparam StoredType The (internal) container to iterate over
\tparam Reference The reference type
*/
template<
	typename StoredType,
	typename Reference
>
class iterator
:
	public fcppt::container::bitfield::detail::iterator_type<
		StoredType,
		Reference
	>::type
{
	typedef typename fcppt::container::bitfield::detail::iterator_type<
		StoredType,
		Reference
	>::type base;
public:
	/**
	\brief The value type associated with the iterator

	The value type is always fcppt::container::bitfield::value_type
	*/
	typedef typename base::value_type value_type;

	/**
	\brief The reference type

	Because it is not possible to provide references to single bits, this
	type is always a an fcppt::container::bitfield::proxy.
	*/
	typedef typename base::reference reference;

	/**
	\brief The difference type
	*/
	typedef typename base::difference_type difference_type;

	/**
	\brief The pointer type

	This is unused
	*/
	typedef typename base::pointer pointer;

	/**
	\brief The iterator categroy, which is random access
	*/
	typedef typename base::iterator_category iterator_category;

	/**
	\brief Creates a singular iterator
	*/
	iterator();
private:
	template<
		typename Enum,
		Enum,
		typename
	> friend class basic;

	iterator(
		StoredType,
		difference_type pos
	);

	typedef typename boost::remove_reference<
		StoredType
	>::type *ref_type;

	ref_type array_;

	difference_type pos_;

	friend class boost::iterator_core_access;

	void
	advance(
		difference_type
	);

	void
	increment();

	void
	decrement();

	bool
	equal(
		iterator const &
	) const;

	Reference
	dereference() const;

	difference_type
	distance_to(
		iterator const &
	) const;

	template<
		typename OtherStoredType,
		typename OtherReference
	>
	friend class iterator;
public:
	template<
		typename OtherStoredType,
		typename OtherReference
	>
	iterator(
		iterator<
			OtherStoredType,
			OtherReference
		> const &
	);
};

}
}
}

#endif
