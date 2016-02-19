//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_HAS_DIM_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_HAS_DIM_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/dim_matches.hpp>
#include <fcppt/math/matrix/object_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Metafunction to check if a static matrix has the specified dimensions

\ingroup fcpptmathmatrix

\tparam Matrix A fcppt::math::matrix::object type

\tparam R The static row count

\tparam C The static column count
*/
template<
	typename Matrix,
	fcppt::math::size_type R,
	fcppt::math::size_type C
>
struct has_dim;

/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S,
	fcppt::math::size_type DR,
	fcppt::math::size_type DC
>
struct has_dim<
	fcppt::math::matrix::object<
		T,
		R,
		C,
		S
	>,
	DR,
	DC
>
:
boost::mpl::and_<
	fcppt::math::detail::dim_matches<
		DR,
		R
	>,
	fcppt::math::detail::dim_matches<
		DC,
		C
	>
>
{
};
/// \endcond

FCPPT_PP_POP_WARNING

}
}
}

#endif
