//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_HAS_DIM_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_HAS_DIM_HPP_INCLUDED

#include <fcppt/math/matrix/basic_fwd.hpp>
#include <fcppt/math/detail/dim_matches.hpp>
#include <fcppt/math/size_type.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <boost/mpl/and.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename Vector,
	size_type N,
	size_type M
>
struct has_dim
:
boost::false_type
{};

template<
	typename T,
	typename N,
	typename M,
	typename S,
	size_type DN,
	size_type DM
>
struct has_dim<
	basic<
		T,
		N,
		M,
		S
	>,
	DN,
	DM
>
:
boost::mpl::and_<
	math::detail::dim_matches<
		DN,
		N::value
	>,
	math::detail::dim_matches<
		DM,
		M::value
	>
>
{};

}
}
}

#endif
