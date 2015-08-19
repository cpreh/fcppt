//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_INIT_HPP_INCLUDED
#define FCPPT_MATH_BOX_INIT_HPP_INCLUDED

#include <fcppt/homogenous_pair.hpp>
#include <fcppt/algorithm/array_fold.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/is_box.hpp>
#include <fcppt/math/detail/init_function.hpp>
#include <fcppt/math/dim/init.hpp>
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

template<
	typename Box,
	typename Function
>
Box
init(
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
		fcppt::algorithm::array_fold<
			result_array
		>(
			fcppt::math::detail::init_function<
				fcppt::math::size_type,
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
					fcppt::math::size_type const _index
				)
				{
					return
						results[
							_index
						].first;
				}
			),
			fcppt::math::dim::init<
				typename
				Box::dim
			>(
				[
					&results
				](
					fcppt::math::size_type const _index
				)
				{
					return
						results[
							_index
						].second;
				}
			)
		);
}

}
}
}

#endif
