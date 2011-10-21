//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_CONTAINS_POINT_HPP_INCLUDED
#define FCPPT_MATH_BOX_CONTAINS_POINT_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/// Tests if @a _box contains @a _point
template<
	typename T,
	size_type N
>
bool
contains_point(
	basic<T, N> const &_box,
	typename vector::static_<T, N>::type const &_point
)
{
	bool ret = true;

	for(
		size_type i = 0;
		i < N;
		++i
	)
		ret = ret &&
			_point[i] >= _box.pos(i)
			&& _point[i] < _box.max(i);

	return ret;
}

}
}
}

#endif
