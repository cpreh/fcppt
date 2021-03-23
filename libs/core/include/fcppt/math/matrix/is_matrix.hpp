//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_IS_MATRIX_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_IS_MATRIX_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/**
\brief Metafunction to test if a type is a matrix type

\ingroup fcpptmathmatrix
*/
template <typename T>
struct is_matrix : std::false_type
{
};

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
struct is_matrix<fcppt::math::matrix::object<T, R, C, S>> : std::true_type
{
};

}
}
}

#endif
