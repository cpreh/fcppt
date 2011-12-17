//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_IS_MATRIX_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_IS_MATRIX_HPP_INCLUDED

#include <fcppt/math/matrix/basic_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/bool.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/**
\brief Metafunction to test if a type is a matrix type
\ingroup fcpptmathmatrix
\tparam T The type to test against
*/
template
<
	typename T
>
struct is_matrix
:
	boost::mpl::false_
{
};

/// \cond FCPPT_DOXYGEN_DEBUG
template
<
	typename T,
	typename N,
	typename M,
	typename S
>
struct is_matrix
<
	matrix::basic<T,N,M,S>
>
:
	boost::mpl::true_
{
};
/// \endcond
}
}
}

#endif
