//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_DETAIL_ARRAY_IMPL_HPP_INCLUDED
#define FCPPT_ASSIGN_DETAIL_ARRAY_IMPL_HPP_INCLUDED

#include <fcppt/assign/detail/array.hpp>
#include <algorithm>

template<
	class T,
	std::size_t N
>
fcppt::assign::detail::array<T,N>::array(
	T const &t
)
{
	a[0] = t;
}

template<
	class T,
	std::size_t N
>
fcppt::assign::detail::array<T,N>::array(
	array<T,N-1> const &that,
	T const &t
)
{
	std::copy(
		that.a.begin(),
		that.a.end(),
		a.begin()
	);

	a.back() = t;
}

template<
	class T,
	std::size_t N
>
fcppt::assign::detail::array<T,N+1>
fcppt::assign::detail::array<T,N>::operator()(
	T const &t
)
{
	return array<T,N+1>(
		*this,
		t
	);
}

template<
	class T,
	std::size_t N
>
fcppt::assign::detail::array<T,N>::operator container_type() const
{
	return a;
}

#endif
