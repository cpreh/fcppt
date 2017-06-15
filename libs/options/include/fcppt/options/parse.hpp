//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PARSE_HPP_INCLUDED
#define FCPPT_OPTIONS_PARSE_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/detail/deref.hpp>
#include <fcppt/options/detail/parse_to_empty.hpp>
#include <fcppt/options/detail/state_from_args.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Parse a command-line.

\ingroup fcpptoptions

Applies \a _parser to \a _args.
*/
template<
	typename Parser
>
fcppt::options::result<
	fcppt::options::result_of<
		Parser
	>
>
parse(
	Parser const &_parser,
	fcppt::args_vector const &_args
)
{
	return
		fcppt::options::detail::parse_to_empty(
			_parser,
			fcppt::options::detail::state_from_args(
				_args,
				fcppt::options::detail::deref(
					_parser
				).parameters()
			)
		);
}

}
}

#endif
