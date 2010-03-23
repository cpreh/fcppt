//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_IS_DYNAMIC_SIZE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_IS_DYNAMIC_SIZE_HPP_INCLUDED

#include <fcppt/math/detail/dynamic_size.hpp>
#include <boost/type_traits/is_same.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
struct is_dynamic_size
:
boost::is_same<
	T,
	dynamic_size
>
{};

}
}
}

#endif
