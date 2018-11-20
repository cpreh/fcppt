//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_INIT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_INIT_HPP_INCLUDED

#include <fcppt/container/array/init.hpp>
#include <fcppt/math/from_array.hpp>
#include <fcppt/math/to_array_type.hpp>
#include <fcppt/math/detail/init_function.hpp>
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
	typename Result,
	typename Function
>
inline
Result
init(
	Function const &_function
)
{
	return
		fcppt::math::from_array<
			Result
		>(
			fcppt::container::array::init<
				fcppt::math::to_array_type<
					Result
				>
			>(
				fcppt::math::detail::init_function<
					std::remove_const_t<
						Function
					>
				>(
					_function
				)
			)
		);
}

}
}
}

#endif
