//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_DETAIL_ELEMENT_BITS_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_DETAIL_ELEMENT_BITS_HPP_INCLUDED

#include <fcppt/container/bitfield/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <limits>
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
	typename T
>
struct element_bits
:
boost::mpl::integral_c<
	bitfield::size_type,
	std::numeric_limits<
		T
	>::digits
>
{
};

}
}
}
}

#endif
