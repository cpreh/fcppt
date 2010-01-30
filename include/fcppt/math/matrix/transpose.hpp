//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_TRANSPOSE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_TRANSPOSE_HPP_INCLUDED

#include <fcppt/math/matrix/basic_fwd.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename T,
	typename N,
	typename M,
	typename S
>
basic<T, M, N, S> const
transpose(
	basic<T, N, M, S> const &);

}
}
}

#include <fcppt/math/matrix/detail/transpose_impl.hpp>

#endif
