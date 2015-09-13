//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_DETAIL_NULL_ARRAY_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_DETAIL_NULL_ARRAY_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/algorithm/array_init.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{
namespace detail
{

template<
	typename Array
>
inline
Array
null_array()
{
	return
		fcppt::algorithm::array_init<
			Array
		>(
			fcppt::literal<
				typename
				Array::value_type
			>(
				0
			)
		);
}

}
}
}
}

#endif
