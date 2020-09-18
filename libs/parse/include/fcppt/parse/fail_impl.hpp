//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_FAIL_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_FAIL_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/fail_decl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


template<
	typename Result
>
fcppt::parse::fail<
	Result
>::fail()
= default;

template<
	typename Result
>
template<
	typename Ch,
	typename Skipper
>
fcppt::parse::result<
	Ch,
	typename
	fcppt::parse::fail<
		Result
	>::result_type
>
fcppt::parse::fail<
	Result
>::parse(
	fcppt::reference<
		fcppt::parse::basic_stream<
			Ch
		>
	>,
	Skipper const &
) const
{
	return
		fcppt::either::make_failure<
			result_type
		>(
			fcppt::parse::error<
				Ch
			>{
				std::basic_string<
					Ch
				>{
					FCPPT_STRING_LITERAL(
						Ch,
						"fail"
					)
				}
			}
		);
}

#endif
