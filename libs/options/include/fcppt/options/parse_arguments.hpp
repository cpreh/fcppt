//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PARSE_ARGUMENTS_HPP_INCLUDED
#define FCPPT_OPTIONS_PARSE_ARGUMENTS_HPP_INCLUDED

#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_arguments_fwd.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/symbol.hpp>


namespace fcppt
{
namespace options
{

class parse_arguments
{
public:
	FCPPT_OPTIONS_DETAIL_SYMBOL
	parse_arguments(
		fcppt::options::state &&,
		fcppt::options::option_name_set &&
	);

	fcppt::options::state state_;

	fcppt::options::option_name_set option_names_;
};

}
}

#endif
