//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_ARGUMENTS_FROM_PARSER_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_ARGUMENTS_FROM_PARSER_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/options/deref.hpp>
#include <fcppt/options/parse_arguments.hpp>
#include <fcppt/options/state.hpp>


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
fcppt::options::parse_arguments
arguments_from_parser(
	fcppt::args_vector const &_args,
	Parser const &_parser
)
{
	return
		fcppt::options::parse_arguments{
			fcppt::options::state{
				fcppt::args_vector{
					_args
				}
			},
			fcppt::options::deref(
				_parser
			).option_names()
		};
}

}
}
}

#endif
