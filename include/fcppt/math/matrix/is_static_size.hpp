//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_IS_STATIC_SIZE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_IS_STATIC_SIZE_HPP_INCLUDED

#include <fcppt/math/is_static_size.hpp>
#include <boost/mpl/and.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

/// Checks if both types specify a static size
template<
	typename N,
	typename M
>
struct is_static_size
:
boost::mpl::and_<
	math::is_static_size<
		N
	>,
	math::is_static_size<
		M
	>
>
{};

}
}
}

#endif
