//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_OPTION_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTION_IMPL_HPP_INCLUDED

#include <fcppt/extract_from_string.hpp>
#include <fcppt/insert_to_fcppt_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/optional/alternative.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/option_decl.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/pretty_type.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/long_or_short_name.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Label,
	typename Type
>
fcppt::options::option<
	Label,
	Type
>::option(
	fcppt::options::optional_short_name const &_short_name,
	fcppt::options::long_name const &_long_name,
	optional_default_value const &_default_value
)
:
	short_name_(
		_short_name
	),
	long_name_(
		_long_name
	),
	default_value_(
		_default_value
	)
{
}

template<
	typename Label,
	typename Type
>
fcppt::options::result<
	typename
	fcppt::options::option<
		Label,
		Type
	>::result_type
>
fcppt::options::option<
	Label,
	Type
>::parse(
	fcppt::options::state &_state
) const
{
	return
		fcppt::optional::maybe(
			fcppt::optional::alternative(
				_state.pop_option(
					long_name_.get(),
					fcppt::options::state::is_short{
						false
					}
				),
				[
					&_state,
					this
				]{
					return
						fcppt::optional::bind(
							short_name_,
							[
								&_state
							](
								fcppt::options::short_name const &_short_name
							)
							{
								return
									_state.pop_option(
										_short_name.get(),
										fcppt::options::state::is_short{
											true
										}
									);
							}
						);
				}
			),
			[
				this
			]{
				return
					fcppt::either::from_optional(
						fcppt::optional::map(
							default_value_.get(),
							[](
								Type const &_value
							)
							{
								return
									result_type{
										Label{} =
											_value
									};
							}
						),
						[
							this
						]{
							return
								fcppt::options::error{
									FCPPT_TEXT("Missing option ")
									+
									fcppt::options::detail::long_or_short_name(
										long_name_,
										short_name_
									)
								};
						}
					);
			},
			[
				this
			](
				fcppt::string const &_string
			)
			{
				return
					fcppt::either::from_optional(
						fcppt::optional::map(
							fcppt::extract_from_string<
								Type
							>(
								_string
							),
							[](
								Type &&_value
							)
							{
								return
									result_type{
										Label{} =
											std::move(
												_value
											)
									};
							}
						),
						[
							this,
							&_string
						]{
							return
								fcppt::options::error{
									FCPPT_TEXT("Failed to convert \"")
									+
									_string
									+
									FCPPT_TEXT("\" to ")
									+
									fcppt::options::pretty_type<
										Type
									>()
									+
									FCPPT_TEXT(" for option ")
									+
									fcppt::options::detail::long_or_short_name(
										long_name_,
										short_name_
									)
								};
						}
					);
			}
		);
}

template<
	typename Label,
	typename Type
>
fcppt::options::has_parameter_set
fcppt::options::option<
	Label,
	Type
>::parameters() const
{
	fcppt::options::has_parameter_set result{
		long_name_.get()
	};

	// TODO: Make a function for this?
	fcppt::optional::maybe_void(
		short_name_,
		[
			&result
		](
			fcppt::options::short_name const &_short_name
		)
		{
			result.insert(
				_short_name.get()
			);
		}
	);

	return
		result;
}

template<
	typename Label,
	typename Type
>
fcppt::string
fcppt::options::option<
	Label,
	Type
>::usage() const
{
	return
		(
			default_value_.get().has_value()
			?
				FCPPT_TEXT("[ ")
			:
				FCPPT_TEXT("")
		)
		+
		fcppt::options::detail::long_or_short_name(
			long_name_,
			short_name_
		)
		+
		FCPPT_TEXT(" :: ")
		+
		fcppt::options::pretty_type<
			Type
		>()
		+
		(
			fcppt::optional::maybe(
				default_value_.get(),
				[]{
					return
						fcppt::string{};
				},
				[](
					Type const &_value
				)
				{
					return
						FCPPT_TEXT(" / ")
						+
						fcppt::insert_to_fcppt_string(
							_value
						);
				}
			)
		)
		+
		(
			default_value_.get().has_value()
			?
				FCPPT_TEXT(" ]")
			:
				FCPPT_TEXT("")
		);
}

#endif
