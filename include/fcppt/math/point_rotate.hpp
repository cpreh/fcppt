//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_POINT_ROTATE_HPP_INCLUDED
#define FCPPT_MATH_POINT_ROTATE_HPP_INCLUDED

#include <fcppt/math/vector/basic_decl.hpp>

namespace fcppt
{
namespace math
{

template<
	typename T,
	typename N,
	typename S
>
vector::basic<T, N, S> const
point_rotate(
	vector::basic<T, N, S> const &point,
	vector::basic<T, N, S> const &around,
	T rot);

}
}

#include <fcppt/math/detail/point_rotate_impl.hpp>

#endif
