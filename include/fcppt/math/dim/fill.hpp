//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_FILL_HPP_INCLUDED
#define FCPPT_MATH_DIM_FILL_HPP_INCLUDED

#include <fcppt/math/detail/fill.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/size_type.hpp>

namespace fcppt
{
namespace math
{
namespace dim
{

/// Creates a dim of Dimension @tparam N with all components set to @param _value
template<
	math::size_type N,
	typename T
>
typename fcppt::math::dim::static_<
	T,
	N
>::type
fill(
	T const &_value
)
{
	return
		fcppt::math::detail::fill<
			typename fcppt::math::dim::static_<
				T,
				N
			>::type
		>(
			_value
		);
}

}
}
}

#endif
