//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MANY_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_MANY_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/use.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/deref.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/many_decl.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/init.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Parser
>
fcppt::options::many<
	Parser
>::many(
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
fcppt::options::many<
	Parser
>::many(
	many const &
)
= default;

template<
	typename Parser
>
fcppt::options::many<
	Parser
>::many(
	many &&
)
= default;

template<
	typename Parser
>
fcppt::options::many<
	Parser
> &
fcppt::options::many<
	Parser
>::operator=(
	many const &
)
= default;

template<
	typename Parser
>
fcppt::options::many<
	Parser
> &
fcppt::options::many<
	Parser
>::operator=(
	many &&
)
= default;

template<
	typename Parser
>
fcppt::options::many<
	Parser
>::~many()
{
}

template<
	typename Parser
>
fcppt::options::parse_result<
	typename
	fcppt::options::many<
		Parser
	>::result_type
>
fcppt::options::many<
	Parser
>::parse(
	fcppt::options::state &&_state,
	fcppt::options::parse_context const &_context
) const
{
	// TODO: This is super ugly
	result_type result{
		fcppt::record::init<
			result_type
		>(
			[](
				auto const _fcppt_options_many_element
			)
			{
				FCPPT_USE(
					_fcppt_options_many_element
				);

				return
					fcppt::record::element_to_type<
						std::remove_const_t<
							decltype(
								_fcppt_options_many_element
							)
						>
					>{};
			}
		)
	};

	fcppt::optional::object<
		fcppt::options::error
	>
	optional_error;

	fcppt::options::state state{
		std::move(
			_state
		)
	};

	// TODO: This is super inefficient. Allow missing_error to return state!
	while(
		!optional_error.has_value()
	)
		fcppt::either::match(
			fcppt::options::deref(
				parser_
			).parse(
				fcppt::options::state{
					state
				},
				_context
			),
			[
				&optional_error
			](
				fcppt::options::error &&_error
			)
			{
				optional_error =
					fcppt::optional::make(
						std::move(
							_error
						)
					);
			},
			[
				&state,
				&result
			](
				fcppt::options::state_with_value<
					fcppt::options::result_of<
						Parser
					>
				> &&_inner
			)
			{
				state =
					std::move(
						_inner.state_
					);

				fcppt::options::result_of<
					Parser
				> &inner_value{
					_inner.value_
				};

				result =
					fcppt::record::init<
						result_type
					>(
						[
							&result,
							&inner_value
						](
							auto const _fcppt_inner_element
						)
						{
							FCPPT_USE(
								_fcppt_inner_element
							);

							typedef
							std::remove_const_t<
								decltype(
									_fcppt_inner_element
								)
							>
							element;

							typedef
							fcppt::record::element_to_label<
								element
							>
							label;

							fcppt::record::element_to_type<
								element
							> new_result{
								std::move(
									fcppt::record::get<
										label
									>(
										result
									)
								)
							};

							new_result.push_back(
								std::move(
									fcppt::record::get<
										label
									>(
										inner_value
									)
								)
							);

							return
								new_result;
						}
					);
			}
		);

	return
		fcppt::variant::match(
			std::move(
				optional_error.get_unsafe()
			),
			[
				&state,
				&result
			](
				fcppt::options::missing_error const &
			)
			{
				return
					fcppt::options::make_success(
						fcppt::options::state_with_value<
							result_type
						>(
							std::move(
								state
							),
							std::move(
								result
							)
						)
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
}

template<
	typename Parser
>
fcppt::options::flag_name_set
fcppt::options::many<
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
fcppt::options::many<
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
fcppt::options::many<
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
		FCPPT_TEXT(" ]*");
}

#endif
