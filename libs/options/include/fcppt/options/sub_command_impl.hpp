//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_SUB_COMMAND_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_SUB_COMMAND_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/sub_command_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Parser
>
fcppt::options::sub_command<
	Parser
>::sub_command(
	fcppt::string &&_name,
	Parser &&_parser
)
:
	name_{
		std::move(
			_name
		)
	},
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
fcppt::string const &
fcppt::options::sub_command<
	Parser
>::name() const
{
	return
		name_;
}

template<
	typename Parser
>
Parser const &
fcppt::options::sub_command<
	Parser
>::parser() const
{
	return
		parser_;
}

#endif
