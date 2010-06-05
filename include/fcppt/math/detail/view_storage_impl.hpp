//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_VIEW_STORAGE_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_VIEW_STORAGE_IMPL_HPP_INCLUDED

#include <fcppt/math/detail/view_storage.hpp>

template<
	typename T,
	typename N
>
fcppt::math::detail::view_storage<T, N>::view_storage(
	pointer const rep,
	size_type const index,
	size_type const stride,
	size_type const sz
)
:
	rep(rep),
	index(index),
	stride(stride),
	sz(sz)
{}

template<
	typename T,
	typename N
>
typename fcppt::math::detail::view_storage<T, N>::reference
fcppt::math::detail::view_storage<T, N>::operator[](
	size_type const i
) const
{
	return rep[i * stride + index];
}

template<
	typename T,
	typename N
>
typename fcppt::math::detail::view_storage<T, N>::pointer
fcppt::math::detail::view_storage<T, N>::data() const
{
	return rep;
}

template<
	typename T,
	typename N
>
typename fcppt::math::detail::view_storage<T, N>::size_type
fcppt::math::detail::view_storage<T, N>::size() const
{
	return sz;
}

#endif
