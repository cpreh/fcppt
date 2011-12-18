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
namespace bitfield
{

/**
\brief A wrapper around a bitfield using an enum
\ingroup fcpptcontainerbitfield

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

