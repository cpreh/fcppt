//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_HAS_DIM_HPP_INCLUDED
#define FCPPT_MATH_DIM_HAS_DIM_HPP_INCLUDED

#include <fcppt/math/dim/basic_fwd.hpp>
#include <fcppt/math/detail/dim_matches.hpp>
#include <fcppt/math/size_type.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace fcppt
{
namespace math
{
namespace dim
{

template<
	typename Dim,
	size_type Size 
>
struct has_dim
:
boost::false_type
{};

template<
	typename T,
	typename N,
	typename S,
	size_type Size
>
struct has_dim<
	basic<
		T,
		N,
		S
	>,
	Size
>
:
detail::dim_matches<
	Size,
	N::value
>
{};

}
}
}

#endif
