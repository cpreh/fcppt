//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ASSIGN_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ASSIGN_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_metal.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/detail/storage_size.hpp>
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
	typename Dest,
	typename Src
>
inline
void
assign(
	Dest &_dest,
	Src const &_src
)
{
	static_assert(
		std::is_same_v<
			fcppt::math::detail::storage_size<
				typename
				Dest::storage_type
			>,
			fcppt::math::detail::storage_size<
				typename
				Src::storage_type
			>
		>
	);

	fcppt::algorithm::loop(
		fcppt::math::int_range_count<
			fcppt::math::detail::storage_size<
				typename
				Src::storage_type
			>::value
		>{},
		[
			&_dest,
			&_src
		](
			auto const _index
		)
		{
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

			_dest.storage()[
				index::value
			] =
				_src.storage()[
					index::value
				];
		}
	);
}

}
}
}

#endif
