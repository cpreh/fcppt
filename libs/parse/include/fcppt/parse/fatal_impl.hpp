//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_FATAL_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_FATAL_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/either/map_failure.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/fatal_decl.hpp>
#include <fcppt/parse/fatal_tag.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Parser
>
fcppt::parse::fatal<
	Parser
>::fatal(
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
template<
	typename Ch,
	typename Skipper
>
fcppt::parse::result<
	Ch,
	typename
	fcppt::parse::fatal<
		Parser
	>::result_type
>
fcppt::parse::fatal<
	Parser
>::parse(
	fcppt::reference<
		fcppt::parse::basic_stream<
			Ch
		>
	> const _state,
	Skipper const &_skipper
) const
{
	return
		fcppt::either::map_failure(
			fcppt::parse::deref(
				this->parser_
			).parse(
				_state,
				_skipper
			),
			[](
				fcppt::parse::error<
					Ch
				> &&_error
			)
			{
				return
					fcppt::parse::error<
						Ch
					>{
						std::move(
							_error.get()
						),
						fcppt::parse::fatal_tag{}
					};
			}
		);
}

#endif
