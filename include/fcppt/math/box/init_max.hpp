//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_INIT_MAX_HPP_INCLUDED
#define FCPPT_MATH_BOX_INIT_MAX_HPP_INCLUDED

#include <fcppt/homogenous_pair.hpp>
#include <fcppt/algorithm/array_fold_static.hpp>
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

/**
// TODO: Document this
// TODO: Unify this with init_dim
\ingroup fcpptmathbox
*/
template<
	typename Box,
	typename Function
>
Box
init_max(
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
		fcppt::algorithm::array_fold_static<
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
					return
						std::get<
							_index
						>(
							results
						).first;
				}
			),
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
					return
						std::get<
							_index
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

#endif
