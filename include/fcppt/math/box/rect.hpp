//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_RECT_HPP_INCLUDED
#define FCPPT_MATH_BOX_RECT_HPP_INCLUDED

#include <fcppt/math/box/basic_fwd.hpp>
#include <fcppt/restrict_typedef_struct.hpp>

namespace fcppt
{
namespace math
{
namespace box
{

/// Typedefs a two dimensional box (a rect)
template<
	typename T
>
struct rect
{
	typedef basic<
		T,
		2
	> type;

	FCPPT_RESTRICT_TYPEDEF_STRUCT(rect)
};

}
}
}

#endif
