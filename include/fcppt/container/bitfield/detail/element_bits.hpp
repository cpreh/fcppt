//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_DETAIL_ELEMENT_BITS_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_DETAIL_ELEMENT_BITS_HPP_INCLUDED

#include <fcppt/container/bitfield/size_type.hpp>
#include <limits>

namespace fcppt
{
namespace container
{
namespace bitfield
{
namespace detail
{

template<
	typename T
>
struct element_bits
{
	static bitfield::size_type const value =
		std::numeric_limits<
			T
		>::digits;
};

}
}
}
}

#endif
