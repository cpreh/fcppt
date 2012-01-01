//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_DYNAMIC_DIM_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_DYNAMIC_DIM_HPP_INCLUDED

#include <fcppt/math/detail/dynamic_size.hpp>
#include <fcppt/math/matrix/detail/dim_storage.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

typedef dim_storage<
	math::detail::dynamic_size,
	math::detail::dynamic_size
> dynamic_dim;

}
}
}
}

#endif
