//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_IS_STATIC_SIZE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_IS_STATIC_SIZE_HPP_INCLUDED

#include <fcppt/math/is_static_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Metafunction to test if a matrix's dimension types are static
\ingroup fcpptmathmatrix
\tparam N The row dimension type
\tparam M The column dimension type
*/
template<
	typename N,
	typename M
>
struct is_static_size
:
boost::mpl::and_<
	math::is_static_size<
		N
	>,
	math::is_static_size<
		M
	>
>
{};

}
}
}

#endif
