//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_RECT_FWD_HPP_INCLUDED
#define FCPPT_MATH_BOX_RECT_FWD_HPP_INCLUDED

#include <fcppt/math/box/object_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Typedefs a two dimensional box (a rect)
\ingroup fcpptmathbox
\tparam T The box's <code>value_type</code>
*/
template<
	typename T
>
using rect
=
fcppt::math::box::object<
	T,
	2
>;

}
}
}

#endif
