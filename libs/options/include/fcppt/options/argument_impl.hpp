//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_ARGUMENT_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_ARGUMENT_IMPL_HPP_INCLUDED

#include <fcppt/extract_from_string.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/type_name_from_info.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/options/argument_decl.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/label_name.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <typeinfo>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Label,
	typename Type
>
fcppt::options::argument<
	Label,
	Type
>::argument(
	fcppt::options::long_name const &_long_name
)
:
	long_name_(
		_long_name
	)
{
}

template<
	typename Label,
	typename Type
>
fcppt::options::result<
	typename
	fcppt::options::argument<
		Label,
		Type
	>::result_type
>
fcppt::options::argument<
	Label,
	Type
>::parse(
	fcppt::options::state &_state
) const
{
	return
		fcppt::either::bind(
			fcppt::either::from_optional(
				_state.pop_arg(),
				[]{
					return
						fcppt::options::error{
							FCPPT_TEXT("Missing argument ")
							+
							fcppt::from_std_string(
								fcppt::record::label_name<
									Label
								>()
							)
						};
				}
			),
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
									FCPPT_TEXT(" for argument ")
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
fcppt::options::argument<
	Label,
	Type
>::parameters() const
{
	return
		fcppt::options::has_parameter_set();
}

template<
	typename Label,
	typename Type
>
fcppt::string
fcppt::options::argument<
	Label,
	Type
>::usage() const
{
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
