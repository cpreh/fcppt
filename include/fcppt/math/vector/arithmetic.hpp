//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_ARITHMETIC_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ARITHMETIC_HPP_INCLUDED

#include <fcppt/math/detail/make_simple_free_function.hpp>
#include <fcppt/math/detail/make_simple_scalar_div.hpp>
#include <fcppt/math/detail/make_simple_scalar_mul.hpp>
#include <fcppt/math/detail/make_simple_unary_minus.hpp>
#include <fcppt/math/vector/normal_storage.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

FCPPT_MATH_DETAIL_MAKE_SIMPLE_FREE_FUNCTION(+)
FCPPT_MATH_DETAIL_MAKE_SIMPLE_FREE_FUNCTION(-)
FCPPT_MATH_DETAIL_MAKE_SIMPLE_FREE_FUNCTION(*)
FCPPT_MATH_DETAIL_MAKE_SIMPLE_FREE_FUNCTION(/)
FCPPT_MATH_DETAIL_MAKE_SIMPLE_FREE_FUNCTION(%)

FCPPT_MATH_DETAIL_MAKE_SIMPLE_UNARY_MINUS

FCPPT_MATH_DETAIL_MAKE_SIMPLE_SCALAR_MUL

FCPPT_MATH_DETAIL_MAKE_SIMPLE_SCALAR_DIV

}
}
}

#endif
