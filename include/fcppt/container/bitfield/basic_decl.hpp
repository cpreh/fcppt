//          Copyright Carl Philipp Reh 2009 - 2012.
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
namespace bitfield
{

/**
\brief A wrapper around a bitfield using an enum
\ingroup fcpptcontainerbitfield
\tparam Enum An enumeration type satisfying the requirements described in the module documentation
\tparam Size The enumeration's size value
\tparam InternalType The internal storage type. Must be unsigned. This fcppt::container::bitfield::default_internal_type by default

See the \link fcpptcontainerbitfield module description \endlink for more information.
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
	/**
	\brief Typedef to the internal storage type (template parameter <code>InternalType</code>
	*/
	typedef InternalType internal_type;

	/**
	\brief A type denoting a reference to a mask value (a reference to a
	boolean, basically).

	Note that this is <em>not</em> a bool or internal_type, but a proxy class.
	*/
	typedef bitfield::proxy<
		array_type &
	> reference;

	/**
	\brief The bitfield's value type, when viewed as a container.

	This forwards to fcppt::container::bitfield::value_type.
	*/
	typedef bitfield::value_type const_reference;

	/**
	\brief A type that provides a random-access iterator that can read or
	modify any element in a bitfield.
	*/
	typedef bitfield::iterator<
		array_type &,
		reference
	> iterator;

	/**
	\brief A type that provides a random-access iterator that can read a
	<code>const</code> element in a bitfield.
	*/
	typedef bitfield::iterator<
		array_type const &,
		const_reference
	> const_iterator;

	/**
	\brief A type that provides a random-access iterator that can read or
	modify any element in a reversed bitfield.
	*/
	typedef std::reverse_iterator<
		iterator
	> reverse_iterator;

	/**
	\brief A type that provides a random-access iterator that can read any
	<code>const</code> element in the bitfield.
	*/
	typedef std::reverse_iterator<
		const_iterator
	> const_reverse_iterator;

	/**
	\brief Constructs an uninitialized bitfield
	*/
	basic();

	/**
	\brief Constructs a bitfield where every bit is valse except the argument's bit.
	\param e The bit that is <em>not</em> set to false
	*/
	explicit basic(
		Enum e
	);

	/**
	\brief Constructs a bitfield where every bit is valse except the right hand side bit.
	\param e The bit that is <em>not</em> set to false
	*/
	basic &
	operator=(
		Enum e
	);

	/**
	\brief Returns a random-access iterator to the first element in the bitfield.
	*/
	iterator
	begin();

	/**
	\brief Returns a random-access iterator to the first element in the bitfield.
	*/
	const_iterator
	begin() const;

	/**
	\brief Returns a random-access iterator that points just beyond the end of the bitfield.
	*/
	iterator
	end();

	/**
	\brief Returns a random-access iterator that points just beyond the end of the bitfield.
	*/
	const_iterator
	end() const;

	/**
	\brief Returns an iterator to the first element in a reversed bitfield.
	*/
	reverse_iterator
	rbegin();


	/**
	\brief Returns an iterator to the first element in a reversed bitfield.
	*/
	const_reverse_iterator
	rbegin() const;

	/**
	\brief Returns an iterator to the end of a reversed bitfield.
	*/
	reverse_iterator
	rend();

	/**
	\brief Returns an iterator to the end of a reversed bitfield.
	*/
	const_reverse_iterator
	rend() const;

	/**
	\brief Returns a random-access const-iterator to the first element in the bitfield.
	*/
	const_iterator
	cbegin() const;

	/**
	\brief Returns a random-access const-iterator that points just beyond the end of the bitfield.
	*/
	const_iterator
	cend() const;

	/**
	\brief Returns a const-iterator to the first element in a reversed bitfield.
	*/
	const_reverse_iterator
	crbegin() const;

	/**
	\brief Returns an iterator to the end of a reversed bitfield.
	*/
	const_reverse_iterator
	crend() const;

	/**
	\brief Returns the number of elements in the bitfield.

	This is the same as <code>Size</code>.
	*/
	size_type
	size() const;

	/**
	\brief Returns a reference (see the reference member type) to the specified bit.
	*/
	const_reference
	operator[](
		Enum
	) const;

	/**
	\brief Returns a reference (see the reference member type) to the specified bit.
	*/
	reference
	operator[](
		Enum
	);

	/**
	\brief Set the specified bit to <code>true</code>
	*/
	basic &
	operator|=(
		Enum
	);

	/**
	\brief Do a bit-wise "or" for all bits.
	*/
	basic &
	operator|=(
		basic const &
	);

	/**
	\brief Do a bit-wise "and" for all bits.
	*/
	basic &
	operator&=(
		basic const &
	);

	/**
	\brief Do a bit-wise "xor" for all bits.
	*/
	basic &
	operator^=(
		basic const &
	);

	/**
	\brief Do a bit-wise "not" for all bits (inverts all bits)
	*/
	basic const
	operator~() const;

	/**
	\brief Checks if all bits are zero

	Return <code>true</code> if all bits are zero, <code>false</code> otherwise.
	*/
	bool
	operator!() const;

	/**
	\brief Checks if the specified bit is set.

	\note
	For some reason VC++ can't find this operator if it is not a member.
	*/
	value_type
	operator &(
		Enum
	) const;

	/**
	\brief Compares two bitfields component-wise
	*/
	bool
	operator==(
		basic const &
	) const;

	/**
	\brief Compares two bitfields lexicographically bit by bit.
	*/
	bool
	operator<(
		basic const &
	) const;

	/**
	\brief Sets the specified bit to true/false
	\param where Which bit to set
	\param value The value to set the bit to
	*/
	void
	set(
		Enum where,
		value_type value
	);

	/**
	\brief Returns if the specified bit is set
	*/
	value_type
	get(
		Enum
	) const;

	/**
	\brief Set all bits to zero.
	*/
	void
	clear();

	/**
	\brief Exchanges the bits of two bitfields.
	*/
	void
	swap(
		basic &
	);

	/**
	\brief Returns the bitfield with all bits set to zero.
	*/
	static
	basic const
	null();
};

/**
\brief Set the specified bit to true
\tparam Enum An enumeration type satisfying the requirements described in the module documentation.
\tparam Size The enumeration's size value.
\tparam InternalType The internal storage type. See fcppt::container::bitfield::basic for more info.
*/
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

/**
\brief Do a bit-wise "or" for all bits.
\tparam Enum An enumeration type satisfying the requirements described in the module documentation.
\tparam Size The enumeration's size value.
\tparam InternalType The internal storage type. See fcppt::container::bitfield::basic for more info.
*/
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

/**
\brief Do a bit-wise "and" for all bits.
\tparam Enum An enumeration type satisfying the requirements described in the module documentation.
\tparam Size The enumeration's size value.
\tparam InternalType The internal storage type. See fcppt::container::bitfield::basic for more info.
*/
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

/**
\brief Do a bit-wise "xor" for all bits.
\tparam Enum An enumeration type satisfying the requirements described in the module documentation.
\tparam Size The enumeration's size value.
\tparam InternalType The internal storage type. See fcppt::container::bitfield::basic for more info.
*/
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

/**
\brief Do a bit-wise "not" for all bits.
\tparam Enum An enumeration type satisfying the requirements described in the module documentation.
\tparam Size The enumeration's size value.
\tparam InternalType The internal storage type. See fcppt::container::bitfield::basic for more info.
*/
template<
	typename Enum,
	Enum Size,
	typename InternalType
>
basic<Enum, Size, InternalType> const
operator~(
	basic<Enum, Size, InternalType>
);

/**
\brief Exchanges the elements of two bitfields.
\tparam Enum An enumeration type satisfying the requirements described in the module documentation.
\tparam Size The enumeration's size value.
\tparam InternalType The internal storage type. See fcppt::container::bitfield::basic for more info.
*/
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

/**
\brief Compares two bitfields component-wise
*/
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

/**
\brief Compares two bitfields component-wise
*/
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

/**
\brief Compares two bitfields lexicographically bit by bit.
*/
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

/**
\brief Compares two bitfields lexicographically bit by bit.
*/
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

/**
\brief Compares two bitfields lexicographically bit by bit.
*/
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

/**
\brief Compares two bitfields lexicographically bit by bit.
*/
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

