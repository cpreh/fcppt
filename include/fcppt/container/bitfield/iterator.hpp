//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_ITERATOR_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_ITERATOR_HPP_INCLUDED

#include <fcppt/container/bitfield/detail/iterator_type.hpp>
#include <fcppt/container/bitfield/iterator_fwd.hpp>
#include <fcppt/container/bitfield/difference_type.hpp>
#include <fcppt/container/bitfield/value_type.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/type_traits/remove_reference.hpp>

namespace fcppt
{
namespace container
{
namespace bitfield
{

template<
	typename StoredType,
	typename Reference
>
class iterator
:
	public detail::iterator_type<
		StoredType,
		Reference
	>::type
{
	typedef typename detail::iterator_type<
		StoredType,
		Reference
	>::type base;
public:
	typedef typename base::value_type value_type;
	typedef typename base::reference reference;
	typedef typename base::difference_type difference_type;
	typedef typename base::iterator_category iterator_category;

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
private:
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
