//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_TO_UNSIGNED_HPP_INCLUDED
#define FCPPT_MATH_DIM_TO_UNSIGNED_HPP_INCLUDED

#include <fcppt/cast/to_unsigned_fun.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Converts a dim into a corresponding unsigned dim

\ingroup fcpptmathdim
*/
template<
	typename T,
	typename N,
	typename S
>
inline
fcppt::math::dim::static_<
	typename
	std::make_unsigned<
		T
	>::type,
	N::value
>
to_unsigned(
	fcppt::math::dim::object<
		T,
		N,
		S
	> const &_src
)
{
	return
		fcppt::math::dim::structure_cast<
			fcppt::math::dim::static_<
				typename
				std::make_unsigned<
					T
				>::type,
				N::value
			>,
			fcppt::cast::to_unsigned_fun
		>(
			_src
		);
}

}
}
}

#endif
