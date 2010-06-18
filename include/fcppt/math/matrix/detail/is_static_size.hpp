//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_IS_STATIC_SIZE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_IS_STATIC_SIZE_HPP_INCLUDED

#include <fcppt/math/detail/is_static_size.hpp>
#include <boost/mpl/and.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

template<
	typename N,
	typename M
>
struct is_static_size
:
boost::mpl::and_<
	math::detail::is_static_size<
		N
	>,
	math::detail::is_static_size<
		M
	>
>
{};

}
}
}
}

#endif
