//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_HAS_SIZE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_HAS_SIZE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/type_traits/is_same.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T,
	size_type N
>
struct has_size
:
boost::is_same<
	T,
	boost::mpl::integral_c<
		size_type,
		N
	>
>
{};

}
}
}

#endif
