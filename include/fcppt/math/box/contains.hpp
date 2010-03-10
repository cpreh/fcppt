//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_CONTAINS_HPP_INCLUDED
#define FCPPT_MATH_BOX_CONTAINS_HPP_INCLUDED

#include <fcppt/math/box/basic_fwd.hpp>

namespace fcppt
{
namespace math
{
namespace box
{

/// Tests if @a inner is inside @a outer
template<
	typename T,
	size_type N
>
bool
contains(
	basic<T, N> const &outer,
	basic<T, N> const &inner
)
{
	bool ret = true;

	for(
		size_type i = 0;
		i < N;
		++i
	)
		ret &=
			inner.pos(i) >= outer.pos(i)
			&& inner.max(i) <= outer.max(i);

	return ret;
}

}
}
}

#endif
