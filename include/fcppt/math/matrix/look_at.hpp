//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_LOOK_AT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_LOOK_AT_HPP_INCLUDED

#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/basic_fwd.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename T,
	typename N,
	typename S
>
typename static_<T, 4, 4>::type const
look_at(
	vector::basic<
		T,
		N,
		S
	> const &eye,
	vector::basic<
		T,
		N,
		S
	> const &location,
	vector::basic<
		T,
		N,
		S
	> const &up
);

}
}
}

#include <fcppt/math/matrix/detail/look_at_impl.hpp>

#endif
