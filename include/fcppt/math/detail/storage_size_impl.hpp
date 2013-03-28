//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_STORAGE_SIZE_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STORAGE_SIZE_IMPL_HPP_INCLUDED

#include <fcppt/math/detail/storage_size_decl.hpp>


template<
	typename Size
>
fcppt::math::detail::storage_size<
	Size
>::storage_size(
	size_type const _size
)
:
	size_(
		_size
	)
{

}

template<
	typename Size
>
typename
fcppt::math::detail::storage_size<
	Size
>::size_type
fcppt::math::detail::storage_size<
	Size
>::get() const
{
	return
		size_;
}

#endif
