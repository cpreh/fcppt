//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_DETAIL_ELEMENT_BITS_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_DETAIL_ELEMENT_BITS_HPP_INCLUDED

#include <fcppt/brigand/integral_cast.hpp>
#include <fcppt/cast/size_fun.hpp>
#include <fcppt/cast/to_unsigned_fun.hpp>
#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{
namespace detail
{

template<
	typename SizeType,
	typename Type
>
using element_bits
=
fcppt::brigand::integral_cast<
	SizeType,
	fcppt::cast::size_fun,
	fcppt::brigand::integral_cast<
		unsigned,
		fcppt::cast::to_unsigned_fun,
		std::integral_constant<
			int,
			std::numeric_limits<
				Type
			>::digits
		>
	>
>;

}
}
}
}

#endif
