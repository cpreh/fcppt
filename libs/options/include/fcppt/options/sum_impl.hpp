//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_SUM_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_SUM_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/options/deref.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/sum_decl.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Left,
	typename LeftLabel,
	typename Right,
	typename RightLabel
>
fcppt::options::sum<
	Left,
	LeftLabel,
	Right,
	RightLabel
>::sum(
	Left &&_left,
	Right &&_right
)
:
	left_{
		std::move(
			_left
		)
	},
	right_{
		std::move(
			_right
		)
	}
{
}

template<
	typename Left,
	typename LeftLabel,
	typename Right,
	typename RightLabel
>
fcppt::options::sum<
	Left,
	LeftLabel,
	Right,
	RightLabel
>::sum(
	sum const &
)
= default;

template<
	typename Left,
	typename LeftLabel,
	typename Right,
	typename RightLabel
>
fcppt::options::sum<
	Left,
	LeftLabel,
	Right,
	RightLabel
>::sum(
	sum &&
)
= default;

template<
	typename Left,
	typename LeftLabel,
	typename Right,
	typename RightLabel
>
fcppt::options::sum<
	Left,
	LeftLabel,
	Right,
	RightLabel
> &
fcppt::options::sum<
	Left,
	LeftLabel,
	Right,
	RightLabel
>::operator=(
	sum const &
)
= default;

template<
	typename Left,
	typename LeftLabel,
	typename Right,
	typename RightLabel
>
fcppt::options::sum<
	Left,
	LeftLabel,
	Right,
	RightLabel
> &
fcppt::options::sum<
	Left,
	LeftLabel,
	Right,
	RightLabel
>::operator=(
	sum &&
)
= default;

template<
	typename Left,
	typename LeftLabel,
	typename Right,
	typename RightLabel
>
fcppt::options::sum<
	Left,
	LeftLabel,
	Right,
	RightLabel
>::~sum()
{
}

template<
	typename Left,
	typename LeftLabel,
	typename Right,
	typename RightLabel
>
fcppt::options::parse_result<
	typename
	fcppt::options::sum<
		Left,
		LeftLabel,
		Right,
		RightLabel
	>::result_type
>
fcppt::options::sum<
	Left,
	LeftLabel,
	Right,
	RightLabel
>::parse(
	fcppt::options::state &&_state,
	fcppt::options::parse_context const &_context
) const
{
	return
		fcppt::either::match(
			fcppt::options::deref(
				left_
			).parse(
				fcppt::options::state{
					_state
				},
				_context
			),
			[
				&_context,
				&_state,
				this
			](
				fcppt::options::error &&
			)
			{
				return
					fcppt::either::map(
						fcppt::options::deref(
							this->right_
						).parse(
							std::move(
								_state
							),
							_context
						),
						[](
							fcppt::options::state_with_value<
								fcppt::options::result_of<
									Right
								>
							> &&_right_result
						)
						{
							return
								fcppt::options::state_with_value<
									result_type
								>{
									std::move(
										_right_result.state_
									),
									result_type{
										right_result{
											RightLabel{} =
												std::move(
													_right_result.value_
												)
										}
									}
								};
						}
					);
			},
			[](
				fcppt::options::state_with_value<
					fcppt::options::result_of<
						Left
					>
				> &&_left_result
			)
			{
				return
					fcppt::options::make_success(
						fcppt::options::state_with_value<
							result_type
						>{
							std::move(
								_left_result.state_
							),
							result_type{
								left_result{
									LeftLabel{} =
										std::move(
											_left_result.value_
										)
								}
							}
						}
					);
			}
		);
}

template<
	typename Left,
	typename LeftLabel,
	typename Right,
	typename RightLabel
>
fcppt::options::flag_name_set
fcppt::options::sum<
	Left,
	LeftLabel,
	Right,
	RightLabel
>::flag_names() const
{
	return
		fcppt::options::flag_name_set{
			fcppt::options::name_set{}
		};
}

template<
	typename Left,
	typename LeftLabel,
	typename Right,
	typename RightLabel
>
fcppt::options::option_name_set
fcppt::options::sum<
	Left,
	LeftLabel,
	Right,
	RightLabel
>::option_names() const
{
	return
		fcppt::options::option_name_set{
			fcppt::options::name_set{}
		};
}

template<
	typename Left,
	typename LeftLabel,
	typename Right,
	typename RightLabel
>
fcppt::string
fcppt::options::sum<
	Left,
	LeftLabel,
	Right,
	RightLabel
>::usage() const
{
	return
		fcppt::options::deref(
			left_
		).usage()
		+
		// TODO: Format this better
		FCPPT_TEXT("\nOR\n")
		+
		fcppt::options::deref(
			right_
		).usage();
}

#endif
