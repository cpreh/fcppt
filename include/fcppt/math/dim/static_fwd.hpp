//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_STATIC_FWD_HPP_INCLUDED
#define FCPPT_MATH_DIM_STATIC_FWD_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
#include <fcppt/math/static_storage.hpp>
#include <fcppt/math/dim/object_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Typedef helper for static dims
\ingroup fcpptmathdim
See the introduction to fcppt::math::vector::object for more information on
static dims (and on this class).
*/
template<
	typename T,
	fcppt::math::size_type N
>
using static_
=
fcppt::math::dim::object<
	T,
	fcppt::math::static_size<
		N
	>,
	fcppt::math::static_storage<
		T,
		fcppt::math::static_size<
			N
		>
	>
>;

}
}
}

#endif
