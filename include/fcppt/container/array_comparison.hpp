//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_COMPARISON_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_COMPARISON_HPP_INCLUDED

#include <fcppt/container/array_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{

template<
	typename T,
	std::size_t N
>
bool
operator==(
	container::array<
		T,
		N
	> const &_a,
	container::array<
		T,
		N
	> const &_b
)
{
	return
		std::equal(
			_a.begin(),
			_a.end(),
			_b.begin()
		);
}

template<
	typename T,
	std::size_t N
>
bool
operator!=(
	container::array<
		T,
		N
	> const &_a,
	container::array<
		T,
		N
	> const &_b
)
{
	return
		!(_a == _b);
}

template<
	typename T,
	std::size_t N
>
bool
operator<(
	container::array<
		T,
		N
	> const &_a,
	container::array<
		T,
		N
	> const &_b
)
{
	return
		std::lexicographical_compare(
			_a.begin(),
			_a.end(),
			_b.begin(),
			_b.end()
		);
}

template<
	typename T,
	std::size_t N
>
bool
operator<=(
	container::array<
		T,
		N
	> const &_a,
	container::array<
		T,
		N
	> const &_b
)
{
	return
		!(_b < _a);
}

template<
	typename T,
	std::size_t N
>
bool
operator>(
	container::array<
		T,
		N
	> const &_a,
	container::array<
		T,
		N
	> const &_b
)
{
	return
		_b < _a;
}

template<
	typename T,
	std::size_t N
>
bool
operator>=(
	container::array<
		T,
		N
	> const &_a,
	container::array<
		T,
		N
	> const &_b
)
{
	return
		!(_a < _b);
}

}
}

#endif
