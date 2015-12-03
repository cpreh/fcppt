//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ROW_TYPE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROW_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief The type to initialize a row with

\ingroup fcpptmathmatrix
*/
template<
	typename Type,
	std::size_t Size
>
using
row_type
=
std::array<
	Type,
	Size
>;

}
}
}

#endif
