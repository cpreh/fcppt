//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_DETAIL_INDEX_ABSOLUTE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_INDEX_ABSOLUTE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/index.hpp>

namespace fcppt::math::matrix::detail
{
template <fcppt::math::size_type C, fcppt::math::size_type Absolute>
using index_absolute = fcppt::math::matrix::index<Absolute / C, Absolute % C>;

}

#endif
