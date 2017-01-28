//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_OPTIONAL_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTIONAL_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/nothing.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/optional_decl.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/detail/deref.hpp>
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
	Parser const &_parser
)
:
	parser_{
		_parser
	}
{
}

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
fcppt::options::result<
	typename
	fcppt::options::optional<
		Parser
	>::result_type
>
fcppt::options::optional<
	Parser
>::parse(
	fcppt::options::state &_state
) const
{
	return
		fcppt::either::match(
			fcppt::options::detail::deref(
				parser_
			).parse(
				_state
			),
			[](
				fcppt::options::error &&_error
			)
			{
				return
					fcppt::variant::match(
						std::move(
							_error
						),
						[](
							fcppt::options::missing_error const &
						)
						{
							return
								fcppt::either::make_success<
									fcppt::options::error
								>(
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
								);
						},
						[](
							fcppt::options::other_error &&_other_error
						)
						{
							return
								fcppt::either::make_failure<
									result_type
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
				fcppt::options::result_of<
					Parser
				> &&_result
			)
			{
				return
					fcppt::either::make_success<
						fcppt::options::error
					>(
						fcppt::record::permute<
							result_type
						>(
							fcppt::record::map(
								std::move(
									_result
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
					);
			}
		);
}

template<
	typename Parser
>
fcppt::options::has_parameter_set
fcppt::options::optional<
	Parser
>::parameters() const
{
	return
		fcppt::options::detail::deref(
			parser_
		).parameters();
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
		fcppt::options::detail::deref(
			parser_
		).usage()
		+
		FCPPT_TEXT(" ]");
}

#endif
