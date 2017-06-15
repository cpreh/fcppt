//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_INTERVAL_HPP_INCLUDED
#define FCPPT_MATH_BOX_INTERVAL_HPP_INCLUDED

#include <fcppt/homogenous_pair.hpp>
#include <fcppt/make_homogenous_pair.hpp>
#include <fcppt/math/at_c.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Creates an interval from a box

\ingroup fcpptmathbox
*/
template<
	fcppt::math::size_type Index,
	typename T,
	fcppt::math::size_type N
>
inline
fcppt::homogenous_pair<
	T
>
interval(
	fcppt::math::box::object<
		T,
		N
	> const &_box
)
{
	return
		fcppt::make_homogenous_pair(
			fcppt::math::at_c<
				Index
			>(
				_box.pos()
			),
			fcppt::math::at_c<
				Index
			>(
				_box.max()
			)
		);
}

}
}
}

#endif
