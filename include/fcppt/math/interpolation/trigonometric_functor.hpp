//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_INTERPOLATION_TRIGONOMETRIC_FUNCTOR_HPP_INCLUDED
#define FCPPT_MATH_INTERPOLATION_TRIGONOMETRIC_FUNCTOR_HPP_INCLUDED

#include <fcppt/math/interpolation/trigonometric.hpp>

namespace fcppt
{
namespace math
{
namespace interpolation
{
struct trigonometric_functor
{
	template<typename Float,typename T>
	T
	operator()(
		Float const &f,
		T const &v1,
		T const &v2) const
	{
		return
			interpolation::trigonometric(
				f,
				v1,
				v2);
	}
};
}
}
}

#endif
