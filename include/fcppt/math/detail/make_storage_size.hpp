//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_STORAGE_SIZE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_STORAGE_SIZE_HPP_INCLUDED	

#include <fcppt/math/detail/storage_size_impl.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Size
>
fcppt::math::detail::storage_size<
	Size
> const
make_storage_size(
	Size const _size
)
{
	return
		fcppt::math::detail::storage_size<
			Size
		>(
			_size
		);
}

}
}
}

#endif
