//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_BITWISE_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_BITWISE_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/detail/strong_typedef/binary_operator.hpp>
#include <fcppt/detail/strong_typedef/unary_operator.hpp>


namespace fcppt
{

/** \addtogroup fcpptstrongtypedef
*  @{
*/
FCPPT_DETAIL_STRONG_TYPEDEF_BINARY_OPERATOR(&)
FCPPT_DETAIL_STRONG_TYPEDEF_BINARY_OPERATOR(|)
FCPPT_DETAIL_STRONG_TYPEDEF_BINARY_OPERATOR(^)

FCPPT_DETAIL_STRONG_TYPEDEF_BINARY_OPERATOR(<<)
FCPPT_DETAIL_STRONG_TYPEDEF_BINARY_OPERATOR(>>)

FCPPT_DETAIL_STRONG_TYPEDEF_UNARY_OPERATOR(~)
/** @}*/

}

#endif
