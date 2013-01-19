//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_NORMAL_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_NORMAL_STORAGE_HPP_INCLUDED

#include <fcppt/math/detail/dynamic_size.hpp>
#include <fcppt/math/detail/dynamic_storage.hpp>
#include <fcppt/math/matrix/detail/static_storage.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	typename N,
	typename M
>
struct normal_storage
:
matrix::detail::static_storage<
	T,
	N::value,
	M::value
>
{
};

template<
	typename T
>
struct normal_storage<
	T,
	math::detail::dynamic_size,
	math::detail::dynamic_size
>
:
math::detail::dynamic_storage<
	T
>
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
