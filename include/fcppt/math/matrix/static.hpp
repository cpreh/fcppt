//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_STATIC_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_STATIC_HPP_INCLUDED

#include <fcppt/math/matrix/basic_fwd.hpp>
#include <fcppt/math/matrix/detail/static_storage.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

/// Typedefs a matrix with static dimensions
template<
	typename T,
	size_type N,
	size_type M
>
struct static_
{
	typedef basic<
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
