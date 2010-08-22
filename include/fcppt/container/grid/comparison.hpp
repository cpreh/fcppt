//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_COMPARISON_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_COMPARISON_HPP_INCLUDED

#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/math/dim/before.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <algorithm>

namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename T,
	size_type N,
	typename A
>
bool
operator==(
	object<T, N, A> const &_a,
	object<T, N, A> const &_b
)
{
	return
		_a.dimension() == _b.dimension()
		&&
		std::equal(
			_a.begin(),
			_a.end(),
			_b.begin()
		);
}

template<
	typename T,
	size_type N,
	typename A
>
bool
operator!=(
	object<T, N, A> const &_a,
	object<T, N, A> const &_b
)
{
	return !(_a == _b);
}

template<
	typename T,
	size_type N,
	typename A
>
bool
operator<(
	object<T, N, A> const &_a,
	object<T, N, A> const &_b
)
{
	return
		_a.dimension()
		!= _b.dimension()
		?
			math::dim::before(
				_a.dimension(),
				_b.dimension()
			)
		:
			std::lexicographical_compare(
				_a.begin(),
				_a.end(),
				_b.begin(),
				_b.end()
			);
}

template<
	typename T,
	size_type N,
	typename A
>
bool
operator>(
	object<T, N, A> const &_a,
	object<T, N, A> const &_b
)
{
	return _b < _a;
}

template<
	typename T,
	size_type N,
	typename A
>
bool
operator<=(
	object<T, N, A> const &_a,
	object<T, N, A> const &_b
)
{
	return !(_a > _b);
}

template<
	typename T,
	size_type N,
	typename A
>
bool
operator>=(
	object<T, N, A> const &_a,
	object<T, N, A> const &_b
)
{
	return !(_a < _b);
}

}
}
}

#endif
