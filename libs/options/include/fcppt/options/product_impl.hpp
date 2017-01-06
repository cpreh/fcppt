//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PRODUCT_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_PRODUCT_IMPL_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/string.hpp>
#include <fcppt/algorithm/set_union.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/options/product_decl.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/record/multiply_disjoint.hpp>


template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
>::product(
	Left const &_left,
	Right const &_right
)
:
	left_(
		_left
	),
	right_(
		_right
	)
{
}

template<
	typename Left,
	typename Right
>
fcppt::options::result<
	result_type
>
fcppt::options::product<
	Left,
	Right
>::parse(
	fcppt::options::state &_state
) const
{
	return
		fcppt::either::bind(
			left_.parse(
				_state
			),
			[](
				typename
				Left::result_type &&_left_result
			)
			{
				return
					fcppt::either::map(
						right_.parse(
							_state
						),
						[](
							typename
							Right::result_type &&_right_result
						)
						{
							return
								fcppt::record::multiply_disjoint(
									_left_result,
									_right_result
								);
						}
					);
			}
		);
}

template<
	typename Left,
	typename Right
>
fcppt::options::has_parameter_set
fcppt::options::product<
	Left,
	Right
>::parameters() const
{
	return
		fcppt::algorithm::set_union(
			left_.parameters(),
			right_.parameters()
		);
}

template<
	typename Left,
	typename Right
>
fcppt::string
fcppt::options::product<
	Left,
	Right
>::usage() const
{
	return
		left_.usage()
		+
		FCPPT_TEXT(' ')
		+
		right_.usage();
}

#endif
