//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_AS_STRUCT_HPP_INCLUDED
#define FCPPT_PARSE_AS_STRUCT_HPP_INCLUDED

#include <fcppt/parse/convert_impl.hpp>
#include <fcppt/parse/make_convert.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Result,
	typename Parser
>
fcppt::parse::convert<
	Result,
	fcppt::type_traits::remove_cv_ref_t<
		Parser
	>
>
as_struct(
	Parser &&_parser
)
{
	return
		fcppt::parse::make_convert<
			Result
		>(
			std::forward<
				Parser
			>(
				_parser
			),
			[](
				fcppt::parse::result_of<
					Parser
				> &&_tuple
			)
			{
				return
					std::apply(
						[](
							auto &&... _args
						)
						{
							return
								Result{
									std::forward<
										decltype(
											_args
										)
									>(
										_args
									)...
								};
						},
						std::move(
							_tuple
						)
					);
			}
		);
}

}
}

#endif
