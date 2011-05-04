//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_STATIC_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_STATIC_HPP_INCLUDED

#include <fcppt/math/vector/basic_fwd.hpp>
#include <fcppt/math/detail/static_storage.hpp>
#include <fcppt/math/size_type.hpp>
#include <boost/mpl/integral_c.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

/// Typedefs a static vector type
template<
	typename T,
	size_type N
>
struct static_
{
	typedef basic<
		T,
		boost::mpl::integral_c<
			size_type,
			N
		>,
		typename math::detail::static_storage<
			T,
			N
		>::type
	> type;
};

}
}
}

#endif
