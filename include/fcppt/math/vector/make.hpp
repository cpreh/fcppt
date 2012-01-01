//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_MAKE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_MAKE_HPP_INCLUDED

#include <fcppt/math/detail/make_impl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/max_ctor_params.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

FCPPT_MATH_DETAIL_MAKE_IMPL(
	FCPPT_MATH_VECTOR_MAX_CTOR_PARAMS
)

}
}
}

#endif
