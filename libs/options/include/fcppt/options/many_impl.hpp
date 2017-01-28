//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MANY_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_MANY_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/use.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/many_decl.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/detail/deref.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/init.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Parser
>
fcppt::options::many<
	Parser
>::many(
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
fcppt::options::result<
	typename
	fcppt::options::many<
		Parser
	>::result_type
>
fcppt::options::many<
	Parser
>::parse(
	fcppt::options::state &_state
) const
{
	// TODO: This is super ugly
	result_type result{
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
					fcppt::record::element_to_type<
						decltype(
							_element
						)
					>{};
			}
		)
	};

	fcppt::optional::object<
		fcppt::options::error
	>
	optional_error;

	while(
		!optional_error.has_value()
	)
		fcppt::either::match(
			fcppt::options::detail::deref(
				parser_
			).parse(
				_state
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
				&result
			](
				fcppt::options::result_of<
					Parser
				> &&_inner
			)
			{
				result =
					fcppt::record::init<
						result_type
					>(
						[
							&result,
							&_inner
						](
							auto const _element
						)
						{
							FCPPT_USE(
								_element
							);

							typedef
							decltype(
								_element
							)
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
										_inner
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
				&result
			](
				fcppt::options::missing_error const &
			)
			{
				return
					fcppt::either::make_success<
						fcppt::options::error
					>(
						std::move(
							result
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
}

template<
	typename Parser
>
fcppt::options::has_parameter_set
fcppt::options::many<
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
fcppt::options::many<
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
		FCPPT_TEXT(" ]*");
}

#endif
