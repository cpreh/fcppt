//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MAKE_OPTIONAL_HPP_INCLUDED
#define FCPPT_OPTIONS_MAKE_OPTIONAL_HPP_INCLUDED

#include <fcppt/options/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Turns a parser into an optional parser.

\ingroup fcpptoptions

Normally, a parser can fail, for example in case an argument has not been
specified. This function turns a parser into a parser that instead of failing
returns an optional result. \a Label is used to store the optional result in a
record.

\tparam Label An \link fcppt::record::label\endlink.
*/
template<
	typename Label,
	typename Parser
>
inline
fcppt::options::optional<
	Label,
	typename
	std::decay<
		Parser
	>::type
>
make_optional(
	Parser &&_parser
)
{
	return
		fcppt::options::optional<
			Label,
			typename
			std::decay<
				Parser
			>::type
		>{
			std::forward<
				Parser
			>(
				_parser
			)
		};
}

}
}

#endif
