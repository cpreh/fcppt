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
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/optional_decl.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Label,
	typename Parser
>
fcppt::options::optional<
	Label,
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
	typename Label,
	typename Parser
>
fcppt::options::optional<
	Label,
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
	typename Label,
	typename Parser
>
fcppt::options::result<
	typename
	fcppt::options::optional<
		Label,
		Parser
	>::result_type
>
fcppt::options::optional<
	Label,
	Parser
>::parse(
	fcppt::options::state &_state
) const
{
	return
		fcppt::either::match(
			parser_.parse(
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
									result_type{
										Label{} =
											optional_result_type{}
									}
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
				typename
				Parser::result_type &&_result
			)
			{
				return
					fcppt::either::make_success<
						fcppt::options::error
					>(
						result_type{
							Label{} =
								fcppt::optional::make(
									std::move(
										_result
									)
								)
						}
					);
			}
		);
}

template<
	typename Label,
	typename Parser
>
fcppt::options::has_parameter_set
fcppt::options::optional<
	Label,
	Parser
>::parameters() const
{
	return
		parser_.parameters();
}

template<
	typename Label,
	typename Parser
>
fcppt::string
fcppt::options::optional<
	Label,
	Parser
>::usage() const
{
	return
		FCPPT_TEXT('[')
		+
		parser_.usage()
		+
		FCPPT_TEXT(']');
}

#endif
