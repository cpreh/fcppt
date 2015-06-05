//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_FILL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_FILL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/init.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Ret
>
Ret
fill(
	typename Ret::value_type const &_value
)
{
	return
		fcppt::math::detail::init<
			Ret
		>(
			[
				&_value
			](
				fcppt::math::size_type
			)
			{
				return
					_value;
			}
		);
}

}
}
}

#endif
