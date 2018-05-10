//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MAKE_COMMANDS_HPP_INCLUDED
#define FCPPT_OPTIONS_MAKE_COMMANDS_HPP_INCLUDED

#include <fcppt/options/commands_impl.hpp>
#include <fcppt/options/sub_command_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Makes a commands parser.

\ingroup fcpptoptions
*/
template<
	typename OptionsParser,
	typename... SubCommands
>
inline
fcppt::options::commands<
	fcppt::type_traits::remove_cv_ref_t<
		OptionsParser
	>,
	SubCommands...
>
make_commands(
	OptionsParser &&_options_parser,
	fcppt::options::sub_command<
		SubCommands
	> &&... _sub_commands
)
{
	return
		fcppt::options::commands<
			fcppt::type_traits::remove_cv_ref_t<
				OptionsParser
			>,
			SubCommands...
		>{
			std::move(
				_options_parser
			),
			std::move(
				_sub_commands
			)...
		};
}

}
}

#endif
