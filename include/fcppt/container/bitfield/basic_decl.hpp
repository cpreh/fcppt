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


#ifndef SGE_CONTAINER_BITFIELD_BASIC_DECL_HPP_INCLUDED
#define SGE_CONTAINER_BITFIELD_BASIC_DECL_HPP_INCLUDED

#include <sge/container/bitfield/basic_fwd.hpp>
#include <sge/container/bitfield/iterator_fwd.hpp>
#include <sge/container/bitfield/proxy_fwd.hpp>
#include <sge/container/bitfield/size_type.hpp>
#include <sge/container/bitfield/value_type.hpp>
#include <sge/safe_bool.hpp>
#include <tr1/array>
#include <iterator>
#include <limits>

// Requires:
// - Enum shall be an enumeration type that doesn't contain any enumerators with explicit values.
//   example 1: enum my_enum { value1, value2, value3 }; is perfectly valid
//   example 2: enum my_enum { value = 100 }; is NOT valid
// - Size shall be the number of enumerators defined in Enum.
//   To achieve consistency you should define the enum's size within the enum itsself.
//   example: enum my_enum { value1, value2, value3, _my_enum_size };
//            typedef basic<my_enum,_my_enum_size> mybasic;
// - operator|(Enum,Enum) shall not be declared!
// - std::numeric_limits<InternalType>::digits shall be the number of bits usable in InternalType

namespace sge
{
namespace container
{
namespace bitfield
{

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
class basic {
	SGE_SAFE_BOOL(basic)
private:
	typedef InternalType internal_type;

	static size_type const element_bits = std::numeric_limits<internal_type>::digits;

	typedef std::tr1::array<
		internal_type,
		Size / element_bits + (Size % element_bits ? 1 : 0)
	> array_type;

	array_type array;

	bool boolean_test() const;
public:
	typedef proxy<
		array_type &,
		element_bits
	> reference;

	typedef value_type const_reference;

	typedef bitfield::iterator<
		array_type &,
		reference,
		element_bits
	> iterator;

	typedef bitfield::iterator<
		array_type const &,
		const_reference,
		element_bits
	> const_iterator;

	typedef std::reverse_iterator<
		iterator
	> reverse_iterator;

	typedef std::reverse_iterator<
		const_iterator
	> const_reverse_iterator;

	basic();

	// intentionally not explicit
	basic(Enum e);

	basic &operator=(Enum e);

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	size_type size() const;

	const_reference operator[](Enum index) const;
	reference operator[](Enum index);

	basic &operator|=(Enum e);
	basic &operator|=(basic const &);
	basic operator|(Enum r) const;
	basic operator|(basic const &) const;

	basic &operator&=(basic const &r);
	basic operator& (basic const &r) const;
	value_type operator& (Enum where) const;

	basic& operator^=(basic const &);
	basic operator^(basic const &) const;

	basic operator~() const;

	void set(
		Enum where,
		value_type value);
	value_type get(Enum where) const;

	void clear();

	bool operator==(basic const &) const;
	bool operator!=(basic const &) const;
};

}
}
}

#endif

