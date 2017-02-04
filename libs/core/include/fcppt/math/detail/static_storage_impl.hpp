//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_STATIC_STORAGE_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STATIC_STORAGE_IMPL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/static_storage_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	fcppt::math::size_type N
>
template<
	typename... Args
>
fcppt::math::detail::static_storage<
	T,
	N
>::static_storage(
	Args &&... _args
)
:
	array_type{{
		std::forward<
			Args
		>(
			_args
		)...
	}}
{
}

template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::detail::static_storage<
	T,
	N
>::static_storage(
	array_type &&_array
)
:
	array_type(
		std::move(
			_array
		)
	)
{
}

template<
	typename T,
	fcppt::math::size_type N
>
typename
fcppt::math::detail::static_storage<
	T,
	N
>::array_type const &
fcppt::math::detail::static_storage<
	T,
	N
>::get() const
{
	return
		*this;
}

#endif
