//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_LINEAR_ACCESS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_LINEAR_ACCESS_HPP_INCLUDED

#include <fcppt/container/to_value_type.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Container
>
inline
fcppt::container::to_value_type<
	Container
>
linear_access(
	Container &_container,
	typename Container::size_type const _index
)
{
	return
		*(
			_container.data()
			+
			_index
		);
}

}
}
}

#endif
