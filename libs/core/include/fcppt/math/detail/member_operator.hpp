//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MEMBER_OPERATOR_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MEMBER_OPERATOR_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/detail/linear_access.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Type1,
	typename Type2,
	typename Function
>
Type1 &
member_operator(
	Type1 &_left,
	Type2 const &_right,
	Function const &_function
)
{
	static_assert(
		Type1::dim_wrapper::value
		==
		Type2::dim_wrapper::value
	);

	fcppt::algorithm::loop(
		fcppt::math::int_range_count<
			Type1::dim_wrapper::value
		>{},
		[
			&_left,
			&_right,
			&_function
		](
			auto const _index
		){
			FCPPT_USE(
				_index
			);

			using
			index
			=
			fcppt::tag_type<
				decltype(
					_index
				)
			>;

			_function(
				fcppt::math::detail::linear_access<
					index::value
				>(
					_left.storage()
				),
				fcppt::math::detail::linear_access<
					index::value
				>(
					_right.storage()
				)
			);
		}
	);

	return
		_left;
}

}
}
}

#endif
