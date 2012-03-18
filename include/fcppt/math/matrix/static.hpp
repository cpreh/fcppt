//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_STATIC_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_STATIC_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/object_fwd.hpp>
#include <fcppt/math/matrix/detail/static_storage.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Typedef helper for static matrices
\ingroup fcpptmathmatrix
\tparam The matrix's <code>value_type</code>
See the introduction to fcppt::math::vector::object for more information on
static matrices (and on this class).
*/
template<
	typename T,
	size_type N,
	size_type M
>
struct static_
{
	typedef object<
		T,
		boost::mpl::integral_c<
			size_type,
			N
		>,
		boost::mpl::integral_c<
			size_type,
			M
		>,
		typename matrix::detail::static_storage<
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
