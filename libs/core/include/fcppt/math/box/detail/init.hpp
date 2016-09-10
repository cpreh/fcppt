//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_DETAIL_INIT_HPP_INCLUDED
#define FCPPT_MATH_BOX_DETAIL_INIT_HPP_INCLUDED

#include <fcppt/homogenous_pair.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/array_init.hpp>
#include <fcppt/math/box/is_box.hpp>
#include <fcppt/math/detail/init_function.hpp>
#include <fcppt/math/vector/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace box
{
namespace detail
{

template<
	typename Box,
	typename InitSecond,
	typename Function
>
Box
init(
	InitSecond const &_init_second,
	Function const &_function
)
{
	static_assert(
		fcppt::math::box::is_box<
			Box
		>::value,
		"Box must be a box::object"
	);

	typedef
	std::array<
		fcppt::homogenous_pair<
			typename
			Box::value_type
		>,
		Box::dim_wrapper::value
	>
	result_array;

	result_array const results(
		fcppt::algorithm::array_init<
			result_array
		>(
			fcppt::math::detail::init_function<
				Function
			>(
				_function
			)
		)
	);

	return
		Box(
			fcppt::math::vector::init<
				typename
				Box::vector
			>(
				[
					&results
				](
					auto const _index
				)
				{
					FCPPT_USE(
						_index
					);

					return
						std::get<
							_index()
						>(
							results
						).first;
				}
			),
			_init_second(
				[
					&results
				](
					auto const _index
				)
				{
					FCPPT_USE(
						_index
					);

					return
						std::get<
							_index()
						>(
							results
						).second;
				}
			)
		);
}

}
}
}
}

#endif
