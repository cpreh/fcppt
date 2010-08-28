//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_QUAD_HPP_INCLUDED
#define FCPPT_MATH_DIM_QUAD_HPP_INCLUDED

#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/math/dim/has_dim.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace math
{
namespace dim
{

template<
	typename Ret
>
typename boost::enable_if<
	fcppt::math::dim::has_dim<
		Ret,
		2
	>,
	Ret
>::type const
quad(
	typename Ret::value_type const &_value
)
{
	return
		Ret(
			_value,
			_value
		);
}

}
}
}

#endif
