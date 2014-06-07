//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_PROXY_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_PROXY_DECL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/container/bitfield/proxy_fwd.hpp>
#include <fcppt/container/bitfield/value_type.hpp>
#include <fcppt/container/bitfield/detail/element_bits.hpp>
#include <fcppt/type_traits/remove_cv_ref.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

/**
\brief The proxy class referencing a single bit in a bitfield

This class is used as a reference type for fcppt::container::bitfield::iterator

\tparam StoredType The internal container type for the bitfield
*/
template<
	typename StoredType
>
class proxy
{
	FCPPT_NONASSIGNABLE(
		proxy
	);

	typedef typename fcppt::type_traits::remove_cv_ref<
		StoredType
	>::type array_type;

	typedef typename array_type::size_type size_type;

	typedef typename array_type::value_type internal_type;

	proxy(
		StoredType array,
		size_type pos
	);

	static size_type const element_bits =
		fcppt::container::bitfield::detail::element_bits<
			size_type,
			internal_type
		>::value;

	StoredType array_;

	size_type const pos_;

	template<
		typename,
		typename
	> friend class iterator;

	static
	size_type
	bit_offset(
		size_type
	);

	static
	size_type
	array_offset(
		size_type
	);

	static
	internal_type
	bit_mask(
		size_type
	);
public:
	/**
	\brief Assigns a new value to the bit

	Assign \a rhs to the bit referenced by this proxy.

	\param rhs The new boolean value
	*/
	proxy &
	operator=(
		fcppt::container::bitfield::value_type rhs
	);

	/**
	\brief Provides conversion into a bool

	Converts into a boolean value. Depending on whether the bit referenced
	by this proxy is set or not, the value will be <code>true</code> or
	<code>false</code>.
	*/
	operator
	fcppt::container::bitfield::value_type() const;
};

}
}
}

#endif
