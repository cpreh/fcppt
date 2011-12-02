//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_BASIC_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_BASIC_DECL_HPP_INCLUDED

#include <fcppt/safe_bool.hpp>
#include <fcppt/container/array_decl.hpp>
#include <fcppt/container/bitfield/array.hpp>
#include <fcppt/container/bitfield/basic_fwd.hpp>
#include <fcppt/container/bitfield/iterator_fwd.hpp>
#include <fcppt/container/bitfield/proxy_fwd.hpp>
#include <fcppt/container/bitfield/size_type.hpp>
#include <fcppt/container/bitfield/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_unsigned.hpp>
#include <iterator>
#include <limits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
/// Contains fcppt::container::bitfield::basic and helper types/functions for it.
namespace bitfield
{

/**
\brief A wrapper around a bitfield using an enum
\ingroup fcpptcontainer

\section bitfield_motivation Motivation

Sometimes you want an enumeration which can take multiple values at once - for
orthogonal options like "a person can be hungry and tired, not hungry and
tired, hungry and not tired or not hungry and not tired". An obvious solution
is using the bit representation of an enumeration:

\code
enum person_status
{
	hungry = 1,
	tired = 1 << 1,
	// insert more options here
};
\endcode

This is tiresome (!) to write and also a little dangerous since the underlying
type of an enumeration can only be an integral type. This means that you rely
upon the fact that you have enough bits available on the target machine --
which might not always be true. Think about a bit field which has more than 64
bits. fcppt::container::bitfield::basic is a template which remedies the
situation.

\section bitfield_requirements Requirements

fcppt::container::bitfield::basic takes as first template parameter an enum
<code>Enum</code> which satisfies the following requirements:

<ul>
<li>
	<code>Enum</code> shall be an enumeration type that doesn't contain any
	enumerators with explicit values.

	<strong>Example 1:</strong>
	\code
	enum my_enum { value1, value2, value3 };
	\endcode

	This is perfectly valid.

	<strong>Example 2:</strong>
	\code
	enum my_enum { value = 100 };
	\endcode

	This is <strong>NOT</strong> valid.
</li>
<li>
	<code>Size</code> shall be the number of enumerators defined in Enum.
	To achieve consistency you should define the enum's size within the
	enum itsself.  <strong>Example:</strong>
	\code
	enum my_enum { value1, value2, value3, _my_enum_size };

	typedef basic<my_enum,_my_enum_size> mybasic;
	\endcode
</li>
<li>
	<code>operator|(Enum,Enum)</code> shall not be declared!
</li>
<li>
	<code>std::numeric_limits<InternalType>::digits</code> shall be the
	number of bits usable in <code>InternalType</code>
</li>
</ul>

\section bitfield_example Example

Here's a small example on how bitfield is used:

\snippet doc/container_bitfield.cpp bitfield

As you can see, you can treat a bitfield like an integral type -- it has the
bitwise <code>operator&, operator|</code> and so on. But you can also treat it
like a <code>std::map<Enum,bool></code> and access elements like that. You
could even iterate through the bitfield like a container.
*/
template<
	typename Enum,
	Enum Size,
	typename InternalType
>
class basic
{
	FCPPT_SAFE_BOOL(basic)
private:
	BOOST_STATIC_ASSERT(
		boost::is_unsigned<
			InternalType
		>::value
	);

	typedef typename bitfield::array<
		Enum,
		Size,
		InternalType
	>::type array_type;

	array_type array_;

	bool
	boolean_test() const;
public:
	typedef InternalType internal_type;

	typedef bitfield::proxy<
		array_type &
	> reference;

	typedef value_type const_reference;

	typedef bitfield::iterator<
		array_type &,
		reference
	> iterator;

	typedef bitfield::iterator<
		array_type const &,
		const_reference
	> const_iterator;

	typedef std::reverse_iterator<
		iterator
	> reverse_iterator;

	typedef std::reverse_iterator<
		const_iterator
	> const_reverse_iterator;

	/// Uninitialized bitfield
	basic();

	/// Initializes every bit to false except the argument's bit
	explicit basic(
		Enum
	);

	basic &
	operator=(
		Enum
	);

	iterator
	begin();

	const_iterator
	begin() const;

	iterator
	end();

	const_iterator
	end() const;

	reverse_iterator
	rbegin();

	const_reverse_iterator
	rbegin() const;

	reverse_iterator
	rend();

	const_reverse_iterator
	rend() const;

	const_iterator
	cbegin() const;

	const_iterator
	cend() const;

	const_reverse_iterator
	crbegin() const;

	const_reverse_iterator
	crend() const;

	size_type
	size() const;

	const_reference
	operator[](
		Enum
	) const;

	reference
	operator[](
		Enum
	);

	basic &
	operator|=(
		Enum
	);

	basic &
	operator|=(
		basic const &
	);

	basic &
	operator&=(
		basic const &
	);

	basic &
	operator^=(
		basic const &
	);

	basic const
	operator~() const;

	bool
	operator!() const;

	// for some reason VC++ can't find this operator if it is not a member
	value_type
	operator &(
		Enum
	) const;

	bool
	operator==(
		basic const &
	) const;

	bool
	operator<(
		basic const &
	) const;

	void
	set(
		Enum where,
		value_type value
	);

	value_type
	get(
		Enum
	) const;

	void
	clear();

	void
	swap(
		basic &
	);

	static
	basic const
	null();
};

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
basic<Enum, Size, InternalType> const
operator|(
	basic<Enum, Size, InternalType> const &,
	Enum
);

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
basic<Enum, Size, InternalType> const
operator|(
	basic<Enum, Size, InternalType> const &,
	basic<Enum, Size, InternalType> const &
);

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
basic<Enum, Size, InternalType> const
operator&(
	basic<Enum, Size, InternalType> const &,
	basic<Enum, Size, InternalType> const &
);

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
basic<Enum, Size, InternalType> const
operator^(
	basic<Enum, Size, InternalType> const &,
	basic<Enum, Size, InternalType> const &
);

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
basic<Enum, Size, InternalType> const
operator~(
	basic<Enum, Size, InternalType>
);

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
void
swap(
	basic<Enum, Size, InternalType> &,
	basic<Enum, Size, InternalType> &
);

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
operator==(
	basic<Enum, Size, InternalType> const &,
	basic<Enum, Size, InternalType> const &
);

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
operator!=(
	basic<Enum, Size, InternalType> const &,
	basic<Enum, Size, InternalType> const &
);

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
operator<(
	basic<Enum, Size, InternalType> const &,
	basic<Enum, Size, InternalType> const &
);

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
operator<=(
	basic<Enum, Size, InternalType> const &,
	basic<Enum, Size, InternalType> const &
);

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
operator>(
	basic<Enum, Size, InternalType> const &,
	basic<Enum, Size, InternalType> const &
);

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
operator>=(
	basic<Enum, Size, InternalType> const &,
	basic<Enum, Size, InternalType> const &
);

}
}
}

#endif

