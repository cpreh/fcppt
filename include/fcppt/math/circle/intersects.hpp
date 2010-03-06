//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_CIRCLE_INTERSECTS_HPP_INCLUDED
#define FCPPT_MATH_CIRCLE_INTERSECTS_HPP_INCLUDED

#include <fcppt/math/circle/basic_fwd.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/size_type.hpp>

namespace fcppt
{
namespace math
{
namespace circle
{

template<
	typename T,
	size_type N
>
bool
intersects(
	basic<T, N> const &a,
	basic<T, N> const &b
)
{
	return
		length(a.origin() - b.origin())
		< a.radius() + b.radius();
}

}
}
}

#endif
