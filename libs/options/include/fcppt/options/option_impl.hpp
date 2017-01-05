//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_OPTION_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTION_IMPL_HPP_INCLUDED

#include <fcppt/extract_from_string.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/type_name_from_info.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/optional/alternative.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/option_decl.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/label_name.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
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
			// TODO: Make a function for this, e.g. a lazy alternative
			fcppt::optional::maybe(
				_state.pop_option(
					fcppt::to_std_string(
						long_name_.get()
					),
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
										fcppt::to_std_string(
											_short_name.get()
										),
										fcppt::options::state::is_short{
											true
										}
									);
							}
						);
				},
				[](
					std::string &&_value
				)
				{
					return
						fcppt::optional::make(
							std::move(
								_value
							)
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
								// TODO: Include short_name/long_name here
								fcppt::options::error{
									FCPPT_TEXT("Missing option ")
									+
									fcppt::from_std_string(
										fcppt::record::label_name<
											Label
										>()
									)
								};
						}
					);
			},
			[](
				std::string const &_string
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
							&_string
						]{
							return
								fcppt::options::error{
									FCPPT_TEXT("Failed to convert \"")
									+
									fcppt::from_std_string(
										_string
									)
									+
									FCPPT_TEXT("\" to ")
									+
									fcppt::type_name_from_info(
										typeid(
											Type
										)
									)
									+
									FCPPT_TEXT(" for option ")
									+
									fcppt::from_std_string(
										fcppt::record::label_name<
											Label
										>()
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
	// TODO: Use fcppt::string?
	fcppt::options::has_parameter_set result{
		fcppt::to_std_string(
			long_name_.get()
		)
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
				fcppt::to_std_string(
					_short_name.get()
				)
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
	// TODO: Better usage
	return
		long_name_.get()
		+
		FCPPT_TEXT(" :: ")
		+
		fcppt::type_name_from_info(
			typeid(
				Type
			)
		);
}

#endif
