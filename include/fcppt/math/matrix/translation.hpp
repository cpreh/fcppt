//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_TRANSLATION_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_TRANSLATION_HPP_INCLUDED

#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename T
>
typename static_<T, 4, 4>::type const
translation(
	T x,
	T y,
	T z
);

}
}
}

#include <fcppt/math/matrix/detail/translation_impl.hpp>

#endif
