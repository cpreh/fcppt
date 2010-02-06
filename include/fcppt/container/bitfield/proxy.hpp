//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_PROXY_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_PROXY_HPP_INCLUDED

#include <fcppt/container/bitfield/proxy_fwd.hpp>
#include <fcppt/container/bitfield/size_type.hpp>
#include <fcppt/container/bitfield/value_type.hpp>
#include <fcppt/nonassignable.hpp>

namespace fcppt
{
namespace container
{
namespace bitfield
{

template<
	typename StoredType,
	size_type ElementBits
>
class proxy
{
	FCPPT_NONASSIGNABLE(proxy)

	proxy(
		StoredType array,
		size_type pos
	);

	StoredType array;
	size_type const pos;

	template<
		typename,
		typename,
		size_type
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
