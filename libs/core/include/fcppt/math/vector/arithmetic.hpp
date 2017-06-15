//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_ARITHMETIC_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ARITHMETIC_HPP_INCLUDED

#include <fcppt/math/detail/make_asymmetric_binary_operator.hpp>
#include <fcppt/math/detail/make_asymmetric_binary_operator_right.hpp>
#include <fcppt/math/detail/make_symmetric_binary_operator.hpp>
#include <fcppt/math/detail/make_unary_operator.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/** \addtogroup fcpptmathvector
*  @{
*/
FCPPT_MATH_DETAIL_MAKE_SYMMETRIC_BINARY_OPERATOR(+)
FCPPT_MATH_DETAIL_MAKE_SYMMETRIC_BINARY_OPERATOR(-)
FCPPT_MATH_DETAIL_MAKE_SYMMETRIC_BINARY_OPERATOR(*)
FCPPT_MATH_DETAIL_MAKE_SYMMETRIC_BINARY_OPERATOR(/)
FCPPT_MATH_DETAIL_MAKE_SYMMETRIC_BINARY_OPERATOR(%)

FCPPT_MATH_DETAIL_MAKE_UNARY_OPERATOR(+)
FCPPT_MATH_DETAIL_MAKE_UNARY_OPERATOR(-)

FCPPT_MATH_DETAIL_MAKE_ASYMMETRIC_BINARY_OPERATOR(+)
FCPPT_MATH_DETAIL_MAKE_ASYMMETRIC_BINARY_OPERATOR(-)
FCPPT_MATH_DETAIL_MAKE_ASYMMETRIC_BINARY_OPERATOR(*)

FCPPT_MATH_DETAIL_MAKE_ASYMMETRIC_BINARY_OPERATOR_RIGHT(/)
FCPPT_MATH_DETAIL_MAKE_ASYMMETRIC_BINARY_OPERATOR_RIGHT(%)
/** @}*/

}
}
}

#endif
