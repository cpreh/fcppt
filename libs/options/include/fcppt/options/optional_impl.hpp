//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_OPTIONAL_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTIONAL_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/nothing.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/deref.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/optional_decl.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value.hpp>
#include <fcppt/record/init.hpp>
#include <fcppt/record/map.hpp>
#include <fcppt/record/permute.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Parser
>
fcppt::options::optional<
	Parser
>::optional(
	Parser &&_parser
)
:
	parser_{
		std::move(
			_parser
		)
	}
{
}

template<
	typename Parser
>
fcppt::options::optional<
	Parser
>::optional(
	optional const &
)
= default;

template<
	typename Parser
>
fcppt::options::optional<
	Parser
>::optional(
	optional &&
)
= default;

template<
	typename Parser
>
fcppt::options::optional<
	Parser
> &
fcppt::options::optional<
	Parser
>::operator=(
	optional const &
)
= default;

template<
	typename Parser
>
fcppt::options::optional<
	Parser
> &
fcppt::options::optional<
	Parser
>::operator=(
	optional &&
)
= default;

template<
	typename Parser
>
fcppt::options::optional<
	Parser
>::~optional()
{
}

template<
	typename Parser
>
fcppt::options::parse_result<
	typename
	fcppt::options::optional<
		Parser
	>::result_type
>
fcppt::options::optional<
	Parser
>::parse(
	fcppt::options::state &&_state,
	fcppt::options::parse_context const &_context
) const
{
	return
		fcppt::either::match(
			fcppt::options::deref(
				parser_
			).parse(
				fcppt::options::state{
					_state
				},
				_context
			),
			[
				&_state
			](
				fcppt::options::error &&_error
			)
			{
				return
					fcppt::variant::match(
						std::move(
							_error
						),
						[
							&_state
						](
							fcppt::options::missing_error const &
						)
						{
							return
								fcppt::options::make_success(
									fcppt::options::state_with_value<
										result_type
									>{
										std::move(
											_state
										),
										fcppt::record::init<
											result_type
										>(
											[](
												auto const _element
											)
											{
												FCPPT_USE(
													_element
												);

												return
													fcppt::optional::nothing{};
											}
										)
									}
								);
						},
						[](
							fcppt::options::other_error &&_other_error
						)
						{
							return
								fcppt::either::make_failure<
									fcppt::options::state_with_value<
										result_type
									>
								>(
									fcppt::options::error{
										std::move(
											_other_error
										)
									}
								);
						}
					);
			},
			[](
				fcppt::options::state_with_value<
					fcppt::options::result_of<
						Parser
					>
				> &&_result
			)
			{
				return
					fcppt::options::make_success(
						fcppt::options::state_with_value<
							result_type
						>{
							std::move(
								_result.state_
							),
							fcppt::record::permute<
								result_type
							>(
								fcppt::record::map(
									std::move(
										_result.value_
									),
									[](
										auto &&_element
									)
									{
										return
											fcppt::optional::make(
												std::move(
													_element
												)
											);
									}
								)
							)
						}
					);
			}
		);
}

template<
	typename Parser
>
fcppt::options::flag_name_set
fcppt::options::optional<
	Parser
>::flag_names() const
{
	return
		fcppt::options::deref(
			parser_
		).flag_names();
}

template<
	typename Parser
>
fcppt::options::option_name_set
fcppt::options::optional<
	Parser
>::option_names() const
{
	return
		fcppt::options::deref(
			parser_
		).option_names();
}

template<
	typename Parser
>
fcppt::string
fcppt::options::optional<
	Parser
>::usage() const
{
	return
		FCPPT_TEXT("[ ")
		+
		fcppt::options::deref(
			parser_
		).usage()
		+
		FCPPT_TEXT(" ]");
}

#endif
