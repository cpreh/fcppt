//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_HAS_DIM_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_HAS_DIM_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/dim_matches.hpp>
#include <fcppt/math/matrix/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Metafunction to check if a static matrix has the specified dimensions
\ingroup fcpptmathmatrix
\tparam Matrix A fcppt::math::matrix::object type
\tparam N The static row count
\tparam N The static column count

This will return <code>false</code> for dynamic matrices.
*/
template<
	typename Matrix,
	size_type N,
	size_type M
>
struct has_dim
:
boost::false_type
{};

/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename T,
	typename N,
	typename M,
	typename S,
	size_type DN,
	size_type DM
>
struct has_dim<
	object<
		T,
		N,
		M,
		S
	>,
	DN,
	DM
>
:
boost::mpl::and_<
	math::detail::dim_matches<
		DN,
		N::value
	>,
	math::detail::dim_matches<
		DM,
		M::value
	>
>
{};
/// \endcond

}
}
}

#endif
