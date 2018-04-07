//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_DETAIL_NULL_ARRAY_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_DETAIL_NULL_ARRAY_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/container/array/init_const.hpp>
#include <fcppt/type_traits/value_type.hpp>


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
		fcppt::container::array::init_const<
			Array
		>(
			fcppt::literal<
				fcppt::type_traits::value_type<
					Array
				>
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
