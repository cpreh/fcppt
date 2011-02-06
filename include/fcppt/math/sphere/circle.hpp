//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_SPHERE_CIRCLE_HPP_INCLUDED
#define FCPPT_MATH_SPHERE_CIRCLE_HPP_INCLUDED

#include <fcppt/math/sphere/basic_fwd.hpp>
#include <fcppt/restrict_typedef_struct.hpp>

namespace fcppt
{
namespace math
{
namespace sphere
{

/// Typedefs a sphere with a dimension of 2 (a circle)
template<
	typename T
>
struct circle
{
	typedef basic<
		T,
		2
	> type;

	FCPPT_RESTRICT_TYPEDEF_STRUCT(
		circle
	);
};

}
}
}

#endif
