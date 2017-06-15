//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_HAS_SIZE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_HAS_SIZE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T,
	fcppt::math::size_type N
>
using has_size
=
std::is_same<
	T,
	fcppt::math::static_size<
		N
	>
>;

}
}
}

#endif
