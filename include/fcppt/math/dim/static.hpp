//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_STATIC_HPP_INCLUDED
#define FCPPT_MATH_DIM_STATIC_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/static_storage.hpp>
#include <fcppt/math/dim/basic_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Typedef helper for static dims
\ingroup fcpptmathdim
See the introduction to fcppt::math::vector::basic for more information on
static dims (and on this class).
*/
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
