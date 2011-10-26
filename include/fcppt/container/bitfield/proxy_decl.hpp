//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_PROXY_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_PROXY_DECL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/container/bitfield/proxy_fwd.hpp>
#include <fcppt/container/bitfield/size_type.hpp>
#include <fcppt/container/bitfield/value_type.hpp>
#include <fcppt/container/bitfield/detail/element_bits.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

template<
	typename StoredType
>
class proxy
{
	FCPPT_NONASSIGNABLE(
		proxy
	);

	proxy(
		StoredType array,
		size_type pos
	);

	static size_type const element_bits =
		bitfield::detail::element_bits<
			typename boost::remove_const<
				typename boost::remove_reference<
					StoredType
				>::type
			>::type::value_type
		>::value;

	StoredType array_;

	size_type const pos_;

	template<
		typename,
		typename
	> friend class iterator;

	static size_type
	bit_offset(
		size_type
	);

	static size_type
	array_offset(
		size_type
	);
public:
	proxy &
	operator=(
		value_type
	);

	operator value_type() const;
};

}
}
}

#endif
