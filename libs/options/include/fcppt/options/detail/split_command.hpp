//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_SPLIT_COMMAND_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_SPLIT_COMMAND_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/string.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/parse_arguments_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

FCPPT_OPTIONS_DETAIL_SYMBOL
fcppt::optional::object<
	std::tuple<
		fcppt::args_vector,
		fcppt::string,
		fcppt::args_vector
	>
>
split_command(
	fcppt::options::parse_arguments const &
);

}
}
}

#endif
