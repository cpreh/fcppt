//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_DIM_MATCHES_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_DIM_MATCHES_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	fcppt::math::size_type Desired,
	fcppt::math::size_type Current
>
using dim_matches
=
std::integral_constant<
	bool,
	Desired
	==
	Current
>;

}
}
}

#endif
