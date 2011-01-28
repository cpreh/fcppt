#ifndef FCPPT_MATH_BOX_HAS_DIM_HPP_INCLUDED
#define FCPPT_MATH_BOX_HAS_DIM_HPP_INCLUDED

#include <fcppt/math/box/basic_fwd.hpp>
#include <fcppt/math/detail/dim_matches.hpp>
#include <fcppt/math/size_type.hpp>

namespace fcppt
{
namespace math
{
namespace box
{
template
<
	typename Box,
	size_type Dim
>
struct has_dim
:
boost::false_type
{};

template<
	typename T,
	size_type N,
	size_type Dim
>
struct has_dim<
	basic<
		T,
		N
	>,
	Dim
>
:
detail::dim_matches<
	Dim,
	N
>
{};
}
}
}

#endif
