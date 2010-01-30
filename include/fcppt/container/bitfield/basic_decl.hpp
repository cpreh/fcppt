//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_BASIC_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_BASIC_DECL_HPP_INCLUDED

#include <fcppt/container/bitfield/basic_fwd.hpp>
#include <fcppt/container/bitfield/iterator_fwd.hpp>
#include <fcppt/container/bitfield/proxy_fwd.hpp>
#include <fcppt/container/bitfield/size_type.hpp>
#include <fcppt/container/bitfield/value_type.hpp>
#include <fcppt/tr1/array.hpp>
#include <fcppt/safe_bool.hpp>
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

namespace fcppt
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
	FCPPT_SAFE_BOOL(basic)
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

