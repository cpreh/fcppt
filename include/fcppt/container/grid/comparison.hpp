//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_COMPARISON_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_COMPARISON_HPP_INCLUDED

#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/detail/equal.hpp>
#include <fcppt/math/dim/before.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
bool
operator==(
	fcppt::container::grid::object<T, N, A> const &_a,
	fcppt::container::grid::object<T, N, A> const &_b
)
{
	return
		_a.size() == _b.size()
		&&
		fcppt::detail::equal(
			_a.begin(),
			_a.end(),
			_b.begin()
		);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
bool
operator!=(
	fcppt::container::grid::object<T, N, A> const &_a,
	fcppt::container::grid::object<T, N, A> const &_b
)
{
	return !(_a == _b);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
bool
operator<(
	fcppt::container::grid::object<T, N, A> const &_a,
	fcppt::container::grid::object<T, N, A> const &_b
)
{
	return
		_a.size()
		!= _b.size()
		?
			fcppt::math::dim::before(
				_a.size(),
				_b.size()
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
	fcppt::container::grid::size_type N,
	typename A
>
bool
operator>(
	fcppt::container::grid::object<T, N, A> const &_a,
	fcppt::container::grid::object<T, N, A> const &_b
)
{
	return _b < _a;
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
bool
operator<=(
	fcppt::container::grid::object<T, N, A> const &_a,
	fcppt::container::grid::object<T, N, A> const &_b
)
{
	return !(_a > _b);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
bool
operator>=(
	fcppt::container::grid::object<T, N, A> const &_a,
	fcppt::container::grid::object<T, N, A> const &_b
)
{
	return !(_a < _b);
}

}
}
}

#endif
