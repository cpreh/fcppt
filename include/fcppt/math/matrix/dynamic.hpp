//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DYNAMIC_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DYNAMIC_HPP_INCLUDED

#include <fcppt/container/raw_vector_decl.hpp>
#include <fcppt/math/detail/dynamic_size.hpp>
#include <fcppt/math/detail/dynamic_storage.hpp>
#include <fcppt/math/matrix/basic_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Typedef helper for dynamic matrices
\tparam The matrix's <code>value_type</code>
\ingroup fcpptmathmatrix
See the introduction to fcppt::math::vector::basic for more information on
dynamic types (and on this class).
*/
template<
	typename T
>
struct dynamic
{
	typedef basic<
		T,
		math::detail::dynamic_size,
		math::detail::dynamic_size,
		typename math::detail::dynamic_storage<
			T
		>::type
	> type;
};

}
}
}

#endif
