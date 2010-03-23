//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_CONTAINS_POINT_HPP_INCLUDED
#define FCPPT_MATH_BOX_CONTAINS_POINT_HPP_INCLUDED

#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/size_type.hpp>

namespace fcppt
{
namespace math
{
namespace box
{

/// Tests if @a box_ contains @a point_
template<
	typename T,
	size_type N
>
bool
contains_point(
	basic<T, N> const &box_,
	typename vector::static_<T, N>::type const &point_
)
{
	bool ret = true;

	for(
		size_type i = 0;
		i < N;
		++i
	)
		ret = ret && 
			point_[i] >= box_.pos(i)
			&& point_[i] < box_.max(i);

	return ret;
}

}
}
}

#endif
