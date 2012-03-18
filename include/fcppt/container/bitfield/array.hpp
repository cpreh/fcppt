//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_ARRAY_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_ARRAY_HPP_INCLUDED

#include <fcppt/container/array_fwd.hpp>
#include <fcppt/container/bitfield/detail/element_bits.hpp>
#include <fcppt/mpl/ceil_div.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

/**
\brief Meta function to retrieve the (quasi-internal) storage type used for fcppt::container::bitfield::object
\tparam Enum The enumeration (see fcppt::container::bitfield::object)
\tparam Size The enumeration's size (see fcppt::container::bitfield::object)
\tparam Internal The internal type (see fcppt::container::bitfield::object)

This is currently just an array of as many <code>InternalTypes</code> values as
necessary to hold all the specified bits.
*/
template<
	typename Enum,
	Enum Size,
	typename InternalType
>
struct array
{
	typedef fcppt::container::array<
		InternalType,
		fcppt::mpl::ceil_div<
			std::size_t,
			Size,
			bitfield::detail::element_bits<
				InternalType
			>::value
		>::value
	> type;
};

}
}
}

#endif
