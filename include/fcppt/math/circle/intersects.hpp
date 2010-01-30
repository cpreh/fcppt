//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_CIRCLE_INTERSECTS_HPP_INCLUDED
#define FCPPT_MATH_CIRCLE_INTERSECTS_HPP_INCLUDED

#include <fcppt/math/circle/basic_fwd.hpp>

namespace fcppt
{
namespace math
{
namespace circle
{

template<
	typename T
>
bool
intersects(
	basic<T> const &,
	basic<T> const &);

}
}
}

#include <fcppt/math/circle/detail/intersects_impl.hpp>

#endif
