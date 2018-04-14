//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_STATE_FROM_PARSER_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_STATE_FROM_PARSER_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/deref.hpp>
#include <fcppt/options/detail/state_from_args.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

template<
	typename Parser
>
inline
fcppt::options::state
state_from_parser(
	fcppt::args_vector const &_args,
	Parser const &_parser
)
{
	return
		fcppt::options::detail::state_from_args(
			_args,
			fcppt::options::detail::deref(
				_parser
			).option_names()
		);
}

}
}
}

#endif
