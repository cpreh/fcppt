//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_NORMAL_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_NORMAL_STORAGE_HPP_INCLUDED

#include <fcppt/math/matrix/detail/static_storage.hpp>
#include <fcppt/math/detail/dynamic_storage.hpp>
#include <fcppt/math/detail/dynamic_size.hpp>
#include <fcppt/restrict_typedef_struct.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

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
	FCPPT_RESTRICT_TYPEDEF_STRUCT(
		normal_storage
	);
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
	FCPPT_RESTRICT_TYPEDEF_STRUCT(
		normal_storage
	);
};

}
}
}

#endif
