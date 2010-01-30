//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_CIRCLE_DETAIL_INTERSECTS_IMPL_HPP_INCLUDED
#define FCPPT_MATH_CIRCLE_DETAIL_INTERSECTS_IMPL_HPP_INCLUDED

#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/basic_impl.hpp>

template<
	typename T
>
bool
fcppt::math::circle::intersects(
	basic<T> const &a,
	basic<T> const &b)
{
	return
		length(a.origin() - b.origin())
		< a.radius() + b.radius();
}

#endif
