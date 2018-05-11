//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_PARSE_TO_EMPTY_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_PARSE_TO_EMPTY_HPP_INCLUDED

#include <fcppt/either/bind.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/options/deref.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/parse_arguments.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/detail/leftover_error.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

template<
	typename Parser
>
fcppt::options::result<
	fcppt::options::result_of<
		Parser
	>
>
parse_to_empty(
	Parser const &_parser,
	fcppt::options::parse_arguments &&_arguments
)
{
	typedef
	fcppt::options::result_of<
		Parser
	>
	result_type;

	return
		fcppt::either::bind(
			fcppt::options::deref(
				_parser
			).parse(
				_arguments
			),
			[
				&_arguments
			](
				result_type &&_result
			)
			{
				typedef
				fcppt::options::result<
					result_type
				>
				return_type;

				FCPPT_PP_PUSH_WARNING
				FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)

				return
					fcppt::optional::maybe(
						fcppt::options::detail::leftover_error(
							_arguments.state_
						),
						[
							&_result
						]{
							return
								return_type{
									std::move(
										_result
									)
								};
						},
						[](
							fcppt::options::error &&_error
						)
						{
							return
								return_type{
									std::move(
										_error
									)
								};
						}
					);

				FCPPT_PP_POP_WARNING
			}
		);
}

}
}
}

#endif
