//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_STATIC_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_STATIC_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
#include <fcppt/math/matrix/object_fwd.hpp>
#include <fcppt/math/matrix/detail/static_storage.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Typedef helper for static matrices
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
See the introduction to fcppt::math::vector::object for more information on
static matrices (and on this class).
*/
template<
	typename T,
	fcppt::math::size_type N,
	fcppt::math::size_type M
>
struct static_
{
	typedef fcppt::math::matrix::object<
		T,
		typename fcppt::math::static_size<
			N
		>::type,
		typename fcppt::math::static_size<
			M
		>::type,
		typename fcppt::math::matrix::detail::static_storage<
			T,
			N,
			M
		>::type
	> type;
};

}
}
}

#endif
