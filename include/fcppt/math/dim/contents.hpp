//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_CONTENTS_HPP_INCLUDED
#define FCPPT_MATH_DIM_CONTENTS_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Returns the area/volume of the dimension

\ingroup fcpptmathdim

This is equal to the product of all components of the dimension.
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
T
contents(
	fcppt::math::dim::object<
		T,
		N,
		S
	> const &_dim
)
{
	return
		fcppt::algorithm::fold(
			_dim.storage(),
			fcppt::literal<
				T
			>(
				1
			),
			std::multiplies<
				T
			>()
		);
}

}
}
}

#endif
