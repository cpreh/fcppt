//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_SUM_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_SUM_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/set_union.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/options/combine_errors.hpp>
#include <fcppt/options/deref.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/indent.hpp>
#include <fcppt/options/make_left.hpp>
#include <fcppt/options/make_right.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value.hpp>
#include <fcppt/options/sum_decl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Label,
	typename Left,
	typename Right
>
fcppt::options::sum<
	Label,
	Left,
	Right
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
	typename Label,
	typename Left,
	typename Right
>
fcppt::options::parse_result<
	typename
	fcppt::options::sum<
		Label,
		Left,
		Right
	>::result_type
>
fcppt::options::sum<
	Label,
	Left,
	Right
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
				fcppt::options::error &&_error1
			)
			{
				FCPPT_PP_PUSH_WARNING
				FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)

				return
					fcppt::either::match(
						fcppt::options::deref(
							this->right_
						).parse(
							std::move(
								_state
							),
							_context
						),
						[
							&_error1
						](
							fcppt::options::error &&_error2
						)
						{
							return
								fcppt::either::make_failure<
									fcppt::options::state_with_value<
										result_type
									>
								>(
									fcppt::options::combine_errors(
										std::move(
											_error1
										),
										std::move(
											_error2
										),
										[](
											fcppt::string &&_string1,
											fcppt::string &&_string2
										)
										{
											// TODO: Format this better
											return
												fcppt::options::indent(
													std::move(
														_string1
													)
												)
												+
												FCPPT_TEXT("\n|\n")
												+
												fcppt::options::indent(
													std::move(
														_string2
													)
												)
												;
										}
									)
								);
						},
						[](
							fcppt::options::state_with_value<
								fcppt::options::result_of<
									Right
								>
							> &&_right_result
						)
						{
							return
								fcppt::options::make_success(
									fcppt::options::state_with_value<
										result_type
									>{
										std::move(
											_right_result.state_
										),
										result_type{
											Label{} =
												variant{
													fcppt::options::make_right(
														std::move(
															_right_result.value_
														)
													)
												}
										}
									}
								);
						}
					);

				FCPPT_PP_POP_WARNING
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
								Label{} =
									variant{
										fcppt::options::make_left(
											std::move(
												_left_result.value_
											)
										)
									}
							}
						}
					);
			}
		);
}

template<
	typename Label,
	typename Left,
	typename Right
>
fcppt::options::flag_name_set
fcppt::options::sum<
	Label,
	Left,
	Right
>::flag_names() const
{
	return
		fcppt::container::set_union(
			fcppt::options::deref(
				left_
			).flag_names(),
			fcppt::options::deref(
				right_
			).flag_names()
		);
}

template<
	typename Label,
	typename Left,
	typename Right
>
fcppt::options::option_name_set
fcppt::options::sum<
	Label,
	Left,
	Right
>::option_names() const
{
	return
		fcppt::container::set_union(
			fcppt::options::deref(
				left_
			).option_names(),
			fcppt::options::deref(
				right_
			).option_names()
		);
}

template<
	typename Label,
	typename Left,
	typename Right
>
fcppt::string
fcppt::options::sum<
	Label,
	Left,
	Right
>::usage() const
{
	return
		FCPPT_TEXT("(\n")
		+
		fcppt::options::indent(
			fcppt::options::deref(
				left_
			).usage()
		)
		+
		FCPPT_TEXT("\n|\n")
		+
		fcppt::options::indent(
			fcppt::options::deref(
				right_
			).usage()
		)
		+
		FCPPT_TEXT("\n)")
		;
}

#endif
