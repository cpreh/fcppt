//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/container/bitfield/array.hpp>
#include <fcppt/container/bitfield/iterator_fwd.hpp>
#include <fcppt/container/bitfield/object_fwd.hpp>
#include <fcppt/container/bitfield/proxy_fwd.hpp>
#include <fcppt/container/bitfield/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

/**
\brief A statically sized bitfield

\ingroup fcpptcontainerbitfield

\tparam ElementType An integral or enumeration type

\tparam NumElements An integral constant wrapper specifying the number of bits

\tparam InternalType The internal storage type. Must be unsigned. This is
fcppt::container::bitfield::default_internal_type by default

See the \link fcpptcontainerbitfield module description \endlink for more information.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
class object
{
private:
	static_assert(
		std::is_unsigned<
			InternalType
		>::value,
		"InternalType must be unsigned"
	);

	typedef typename fcppt::container::bitfield::array<
		ElementType,
		NumElements,
		InternalType
	>::type array_type;

	array_type array_;
public:
	/**
	\brief Typedef to <code>ElementType</code>
	*/
	typedef ElementType element_type;

	/**
	\brief The size type which is taken from <code>NumElements</code>
	*/
	typedef typename NumElements::value_type size_type;

	/**
	\brief The value type, which is bool
	*/
	typedef fcppt::container::bitfield::value_type value_type;

	/**
	\brief Typedef to <code>NumElements</code>
	*/
	typedef NumElements static_size;

	/**
	\brief Typedef to the internal storage type (template parameter <code>InternalType</code>
	*/
	typedef InternalType internal_type;

	/**
	\brief Typedef to a pointer to the internal storage type
	*/
	typedef typename array_type::pointer pointer;

	/**
	\brief Typedef to a pointer to the const internal storage type
	*/
	typedef typename array_type::const_pointer const_pointer;

	/**
	\brief A type denoting a reference to a mask value (a reference to a
	boolean, basically).

	Note that this is <em>not</em> a bool or internal_type, but a proxy class.
	*/
	typedef fcppt::container::bitfield::proxy<
		array_type &
	> reference;

	/**
	\brief The bitfield's value type, when viewed as a container.

	This forwards to fcppt::container::bitfield::value_type.
	*/
	typedef fcppt::container::bitfield::value_type const_reference;

	/**
	\brief A type that provides a random-access iterator that can read or
	modify any element in a bitfield.
	*/
	typedef fcppt::container::bitfield::iterator<
		array_type &,
		reference
	> iterator;

	/**
	\brief A type that provides a random-access iterator that can read a
	<code>const</code> element in a bitfield.
	*/
	typedef fcppt::container::bitfield::iterator<
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
	explicit
	object(
		fcppt::no_init const &
	);

	/**
	\brief Constructs a bitfield where every bit is false except the argument's bit.
	\param e The bit that is <em>not</em> set to false
	*/
	explicit
	object(
		ElementType e
	);

	/**
	\brief Constructs a bitfield where every bit is false except the right hand side bit.
	\param e The bit that is <em>not</em> set to false
	*/
	object &
	operator=(
		ElementType e
	);

	/**
	\brief Returns a pointer to the internal storage.
	*/
	pointer
	data();

	/**
	\brief Returns a pointer to the const internal storage.
	*/
	const_pointer
	data() const;

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

	This is the same as <code>NumElements::value</code>.
	*/
	size_type
	size() const;

	/**
	\brief Returns a reference (see the reference member type) to the specified bit.
	*/
	const_reference
	operator[](
		ElementType
	) const;

	/**
	\brief Returns a reference (see the reference member type) to the specified bit.
	*/
	reference
	operator[](
		ElementType
	);

	/**
	\brief Set the specified bit to <code>true</code>
	*/
	object &
	operator|=(
		ElementType
	);

	/**
	\brief Do a bit-wise "or" for all bits.
	*/
	object &
	operator|=(
		object const &
	);

	/**
	\brief Do a bit-wise "and" for all bits.
	*/
	object &
	operator&=(
		object const &
	);

	/**
	\brief Do a bit-wise "xor" for all bits.
	*/
	object &
	operator^=(
		object const &
	);

	/**
	\brief Do a bit-wise "not" for all bits (inverts all bits)
	*/
	object const
	operator~() const;

	/**
	\brief Checks if at least one bit is non zero

	Return <code>false</code> if all bits are zero, <code>true</code> otherwise.
	*/
	explicit
	operator
	bool() const;

	/**
	\brief Checks if the specified bit is set.

	\note
	For some reason VC++ can't find this operator if it is not a member.
	*/
	value_type
	operator &(
		ElementType
	) const;

	/**
	\brief Compares two bitfields component-wise
	*/
	bool
	operator==(
		object const &
	) const;

	/**
	\brief Compares two bitfields lexicographically bit by bit.
	*/
	bool
	operator<(
		object const &
	) const;

	/**
	\brief Sets the specified bit to true/false
	\param where Which bit to set
	\param value The value to set the bit to
	*/
	void
	set(
		ElementType where,
		value_type value
	);

	/**
	\brief Returns if the specified bit is set
	*/
	value_type
	get(
		ElementType
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
		object &
	);

	/**
	\brief Returns the bitfield with all bits set to zero.
	*/
	static
	object const
	null();
};

/**
\brief Set the specified bit to true
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
> const
operator|(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	ElementType
);

/**
\brief Do a bit-wise "or" for all bits.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
> const
operator|(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Do a bit-wise "and" for all bits.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
> const
operator&(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Do a bit-wise "xor" for all bits.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
> const
operator^(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Do a bit-wise "not" for all bits.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
fcppt::container::bitfield::object<
	ElementType,
	NumElements,
	InternalType
> const
operator~(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	>
);

/**
\brief Exchanges the elements of two bitfields.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
void
swap(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> &
);

/**
\brief Compares two bitfields component-wise
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator==(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Compares two bitfields component-wise
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator!=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Compares two bitfields lexicographically bit by bit.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator<(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Compares two bitfields lexicographically bit by bit.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator<=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Compares two bitfields lexicographically bit by bit.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator>(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

/**
\brief Compares two bitfields lexicographically bit by bit.
*/
template<
	typename ElementType,
	typename NumElements,
	typename InternalType
>
bool
operator>=(
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &,
	fcppt::container::bitfield::object<
		ElementType,
		NumElements,
		InternalType
	> const &
);

}
}
}

#endif

