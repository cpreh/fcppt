/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_CONTAINER_BITFIELD_ITERATOR_HPP_INCLUDED
#define SGE_CONTAINER_BITFIELD_ITERATOR_HPP_INCLUDED

#include <sge/container/bitfield/detail/iterator_type.hpp>
#include <sge/container/bitfield/iterator_fwd.hpp>
#include <sge/container/bitfield/size_type.hpp>
#include <sge/container/bitfield/difference_type.hpp>
#include <sge/container/bitfield/value_type.hpp>
#include <boost/iterator/iterator_facade.hpp>

namespace sge
{
namespace container
{
namespace bitfield
{

template<
	typename StoredType,
	typename Reference,
	size_type ElementBits
>
class iterator
:
	public detail::iterator_type<
		StoredType,
		Reference,
		ElementBits
	>::type
{
	typedef typename detail::iterator_type<
		StoredType,
		Reference,
		ElementBits
	>::type base;
public:
	typedef typename base::value_type value_type;
	typedef typename base::reference reference;
	typedef typename base::difference_type difference_type;
	typedef typename base::iterator_category iterator_category;
private:
	template<
		typename Enum,
		Enum,
		typename
	> friend class basic;

	iterator(
		StoredType array,
		size_type pos);

	StoredType array;
	size_type pos;

	friend class boost::iterator_core_access;

	void advance(difference_type d);
	void increment();
	void decrement();
	bool equal(iterator const &) const;
	Reference dereference() const;

	template<
		typename OtherStoredType,
		typename OtherReference,
		size_type OtherElementBits
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
			OtherReference,
			ElementBits
		> const &r);
};

}
}
}

#endif
